# Step 3: Finish `TwoViewRelativePoseEstimator`

First, take a look at the definition and documentation in [two_view_relative_pose_estimator.h]. 
Then go to [two_view_relative_pose_estimator.cpp]. 
Read through the code to get an overview. 

## 1. Understand
Study `TwoViewRelativePoseEstimator::estimate()` in [two_view_relative_pose_estimator.cpp:11], and try to understand what is happening here.

[two_view_relative_pose_estimator.h]:      https://github.com/tek5030/lab-simple-vo/blob/master/two_view_relative_pose_estimator.h
[two_view_relative_pose_estimator.cpp]:    https://github.com/tek5030/lab-simple-vo/blob/master/two_view_relative_pose_estimator.cpp
[two_view_relative_pose_estimator.cpp:11]: https://github.com/tek5030/lab-simple-vo/blob/master/two_view_relative_pose_estimator.cpp#11

## 2. Use the 5-point algorithm to find an inlier set
Use the 5-point algorithm to find an inlier set that fits with a common epipolar geometry.

See [cv::findEssentialMat()].

## 3. Compute the fundamental matrix based on the inlier set
Based on the inlier set from 2., compute the fundamental matrix using the 8-point algorithm.

Why shouldn't we use RANSAC here?

See [cv::findFundamentalMat()].

## 4. Compute the essential matrix from the fundamental matrix
Now that we have the fundamental matrix, we can compute the essential matrix using the camera calibration matrix.

See [Lecture: Epipolar geometry](https://www.uio.no/studier/emner/matnat/its/TEK5030/v23/lectures/11-two-view-geometry/epipolar-geometry_2023.pdf)

## 5. Recover pose from the essential matrix
With the essential matrix, we are finally ready to estimate the relative pose between the two cameras. Decompose the essential matrix to recover the pose.

See [cv::recoverPose()].

You should now be able to compile, run and test the pose estimator. 
You will definitely want to run the program in Release, when you are finished debugging.

Make sure the image window is in focus:
- Press \<space\> to do 2-view pose estimation and 3D reconstruction.
- Press \<space\> again to construct a 3D map.
  - You will now use the Motion-only pose estimator from lab 6 to estimate motion relative to this map.
- Press \<space\> again to construct a new 3D map based on the last keyframe and the current frame.
- Continue moving around by creating new maps!

- Press \<r\> to reset the map.
- Press any other key to quit.

Play around with the two-view geometry!
Then continue to [the last page](4-further-experiments.md).

[cv::findEssentialMat()]:   https://docs.opencv.org/4.5.5/d9/d0c/group__calib3d.html#ga13f7e34de8fa516a686a56af1196247f
[cv::findFundamentalMat()]: https://docs.opencv.org/4.5.5/d9/d0c/group__calib3d.html#ga30ccb52f4e726daa039fd5cb5bf0822b
[cv::recoverPose()]:        https://docs.opencv.org/4.5.5/d9/d0c/group__calib3d.html#gadb7d2dfcc184c1d2f496d8639f4371c0