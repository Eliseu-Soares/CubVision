#include "../../cubo_bonus.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int	udp_init(t_udp *udp)
{
	int	opt;

	udp->fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (udp->fd < 0)
	{
		perror("socket");
		return (1);
	}

	memset(&udp->addr, 0, sizeof(udp->addr));

	udp->addr.sin_family = AF_INET;
	udp->addr.sin_addr.s_addr = htonl(INADDR_ANY);
	udp->addr.sin_port = htons(UDP_PORT);

	if (bind(udp->fd,
			(struct sockaddr *)&udp->addr,
			sizeof(udp->addr)) < 0)
	{
		perror("bind");
		close(udp->fd);
		return (1);
	}

	opt = fcntl(udp->fd, F_GETFL, 0);
	if (opt < 0)
	{
		perror("fcntl");
		close(udp->fd);
		return (1);
	}

	if (fcntl(udp->fd, F_SETFL, opt | O_NONBLOCK) < 0)
	{
		perror("fcntl");
		close(udp->fd);
		return (1);
	}

	printf("UDP initialized on port %d\n", UDP_PORT);

	return (0);
}

int	udp_receive(t_udp *udp)
{
	int	bytes_received;

	bytes_received = recvfrom(
		udp->fd,
		udp->buffer,
		UDP_BUFFER_SIZE - 1,
		0,
		NULL,
		NULL
	);

	if (bytes_received < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
			return (0);
		perror("recvfrom");
		return (-1);
	}

	udp->buffer[bytes_received] = '\0';
	return (bytes_received);
}

void	udp_close(t_udp *udp)
{
	if (udp->fd >= 0)
		close(udp->fd);
}

void	handle_udp_command(t_cubo *cubo, char command)
{
	//Rotation	
	if (command == 'L')
	{
		cubo->side_rotate= -1;
		cubo->speed_rotate = ROT_SPEED;
		/* cubo->speed_rotate *= fabs(7 / (S_WIDTH / 2.0) - 1); */
	}
	else if (command == 'R')
	{
		cubo->side_rotate = 1;
		cubo->speed_rotate = ROT_SPEED;
		//cubo->speed_rotate *= (x - S_WIDTH / 2.0) / (S_WIDTH / 2.0);
	}
	else if (command == 'S')
		cubo->side_rotate = 0;
}

int init_udp(t_cubo *cubo)
{
	if (udp_init(&cubo->udp) == 1) {
		printf("Error!");
		return (1);
	}
	return (0);
}
