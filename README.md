# Visual Odometry

Welcome to this lab in the computer vision course [TEK5030] at the University of Oslo.

This lab will be similar to the lab [Pose estimation and augmented reality](https://github.com/tek5030/lab-pose-estimation), but we will now create our own 3D maps instead of relying on known planar world points.
This will also enable us to implement a very naive visual odometry method.

Start by cloning this repository on your machine.
Then, open the lab project in your editor.

The lab is carried out by following these steps:

1. [Get an overview](lab-guide/1-get-an-overview.md)
2. [Calibrate the camera](lab-guide/2-calibrate-the-camera.md)
3. [Finish TwoViewRelativePoseEstimator](lab-guide/3-finish-twoviewrelativeposeestimator.md)
4. [Further experiments](lab-guide/4-further-experiments.md)

You will find our proposed solution at https://github.com/tek5030/solution-simple-vo.

Please try to solve the lab with help from others instead of just jumping straight to the solution ;)

Start the lab by going to the [first step](lab-guide/1-get-an-overview.md).

## Prerequisites

As in [lab-stereo], you will need to install the [tek5030 camera-library] for the lab. Head over to the repository and follow the installation instructions.   
Note: The camera-library is preinstalled on the lab computers and in the [`tek5030/devcontainer`] Docker image.

For this lab, we can unfortunately not rely on conan to install all required OpenCV modules (namely the `viz` module for 3D visualization). You have a few other options:

- Solve the [python lab](https://github.com/tek5030/lab-simple-vo-py) (recommended)
- Use the lab computers
- Install OpenCV using [homebrew](https://brew.sh/) (option for mac and linux). (See also [Getting started on MacOS](https://tek5030.github.io/tutorial/macos.html).)
- Try [Docker toolchain][docker-toolchain] in CLion (fairly experimental)
- Try [devcontainer][devcontainer] in VS Code (fairly experimental)
- Rely on virtualbox and our prepared linux image with dependencies preinstalled (see [Canvas: Setting up your computer for the labs](https://uio.instructure.com/courses/44675/discussion_topics/295673))


[repo]:  https://github.com/tek5030/lab-simple-vo
[guide]: https://github.com/tek5030/lab-simple-vo/blob/master/README.md

[TEK5030]: https://www.uio.no/studier/emner/matnat/its/TEK5030/
[conan]: https://tek5030.github.io/tutorial/conan.html
[lab_intro]: https://github.com/tek5030/lab-intro/blob/master/cpp/lab-guide/1-open-project-in-clion.md#6-configure-project
[docker-toolchain]: https://tek5030.github.io/tutorial/docker-toolchain.html
[devcontainer]: https://tek5030.github.io/tutorial/devcontainer.html

[lab-stereo]: https://github.com/tek5030/lab-stereo
[tek5030 camera-library]: https://github.com/tek5030/camera-library
[`tek5030/devcontainer`]: https://hub.docker.com/r/tek5030/devcontainer