from smoothing import ExponentialSmoother


smoother = ExponentialSmoother(alpha=0.2)

values = [
    0.50,
    0.52,
    0.48,
    0.53,
    0.49,
    0.51,
    0.50,
]

for value in values:
    smooth = smoother.update(value)

    print(
        f"raw={value:.3f} "
        f"smooth={smooth:.3f}"
    )
