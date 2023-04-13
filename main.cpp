#include "calibrated_opencv_camera.h"
#include "lab_vo.h"
#include <iostream>


int main()
{
  try
  {
    // Todo 1: Remember to setup the calibration if you are using you own camera.
    constexpr int camera_id = 0;
    auto camera = std::make_shared<CalibratedOpencvCamera>(camera_id);

    LabVO lab(camera);
    lab.run();
  }
  catch (const std::exception& e)
  {
    std::cerr << "Caught exception:\n"
              << e.what() << "\n";
  }
  catch (...)
  {
    std::cerr << "Caught unknown exception\n";
  }

  return EXIT_SUCCESS;
}
