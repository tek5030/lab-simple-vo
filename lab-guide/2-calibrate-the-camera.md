# Step 2: Calibrate the camera
To estimate the pose of the camera using correspondences, we will first need to specify the camera calibration parameters.

We have made a camera interface `CalibratedCamera`, which supports both Realsense cameras through the implementation `CalibratedRealSenseCamera`, and OpenCV cameras through `CalibratedOpencvCamera`.
These classes also contain the camera calibration.

You have the following choice of cameras:
- ~~Use the precalibrated RealSense camera available at the lab with `CalibratedRealSenseCamera`.
  This is the recommended choice.~~
- ~~Use a web camera available at the lab with `CalibratedOpencvCamera`.
  In this case, you can use the calibration results in [cameraParameters.xml](https://github.com/tek5030/lab_06/blob/master/cameraParameters.xml).
  We have already filled in these data in the camera interface.~~
- Use your own camera with `CalibratedOpencvCamera`.
  In this case, you will have to calibrate the camera, and setup the parameters in `setupCalibration()` in [calibrated_opencv_camera.cpp:3](https://github.com/tek5030/lab_08/blob/master/calibrated_opencv_camera.cpp#L3)

## 1. Choose the camera and, optionally, specify the camera calibration
Goto [main.cpp](https://github.com/tek5030/lab_08/blob/master/main.cpp) and choose the camera you want to use (by commenting out the code you do not want to use ;) ).

If you are using your own camera, [you need to calibrate it](https://docs.opencv.org/4.0.1/d7/d21/tutorial_interactive_calibration.html), and update the calibration parameters in `setupCalibration()` in [calibrated_opencv_camera.cpp:3](https://github.com/tek5030/lab_08/blob/master/calibrated_opencv_camera.cpp#L3).

Then, please continue to the [next step](3-finish-twoviewrelativeposeestimator.md).