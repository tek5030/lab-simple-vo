# Step 2: Calibrate the camera
To estimate the pose of the camera using correspondences, we will first need to specify the camera calibration parameters.

We have made a camera interface `CalibratedCamera`, which supports both Realsense cameras through the implementation `CalibratedRealSenseCamera`, and OpenCV cameras through `CalibratedOpencvCamera`.
These classes also contain the camera calibration.

As in [lab-stereo], you will need the [tek5030 camera-library] for the lab. Head over to the repository and follow the installation instructions.   
Note: The camera-library is preinstalled on the lab computers and in the [`tek5030/devcontainer`] Docker image.

[lab-stereo]: https://github.com/tek5030/lab-stereo
[tek5030 camera-library]: https://github.com/tek5030/camera-library
[`tek5030/devcontainer`]: https://hub.docker.com/r/tek5030/devcontainer

You have the following choice of cameras:

- Use `CalibratedRealSenseCamera` with the precalibrated RealSense camera available at the lab.

  This is the recommended choice.

- Use `CalibratedOpencvCamera` with a web camera available at the lab.

  In this case, you can use the calibration results in [cameraParameters.xml] from lab "Pose estimation".
  We have already filled in these data in the camera interface.

- Use `CalibratedOpencvCamera` with your own camera.

  In this case, you will have to calibrate the camera, and setup the parameters in `setupCalibration()` in [calibrated_opencv_camera.cpp:3]

## 1. Choose the camera and, optionally, specify the camera calibration
Goto [main.cpp] and choose the camera you want to use (by commenting out the code you do not want to use ;) ).

If you are using your own camera, [you need to calibrate it][calibration-tutorial], and update the calibration parameters in `setupCalibration()` in [calibrated_opencv_camera.cpp:3].

Then, please continue to the [next step](3-finish-twoviewrelativeposeestimator.md).

[main.cpp]: https://github.com/tek5030/lab-simple-vo/blob/master/main.cpp
[calibrated_opencv_camera.cpp:3]: https://github.com/tek5030/lab-simple-vo/blob/master/calibrated_opencv_camera.cpp#L3
[cameraParameters.xml]: https://github.com/tek5030/lab-pose-estimation/blob/master/cameraParameters.xml
[calibration-tutorial]: https://docs.opencv.org/4.5.5/d7/d21/tutorial_interactive_calibration.html
