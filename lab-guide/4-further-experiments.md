# Step 4: Further experiements

## Experiments
How does the very *naive* VO method work?
- Try moving around, ending up at the same position as you started. 
  Is the estimated pose near the starting pose?
- Can you construct a 3D model while moving towards or away from the scene?

## Further suggestions
- Compute and visualize epipolar lines for points.
- Study the Structure-only BA method in `SobaPointsEstimator`.
  - Implement Levenberg-Marquardt.
- Add more views to the `SobaPointsEstimator` to triangulate the points better.

