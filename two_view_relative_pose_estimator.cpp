#include "two_view_relative_pose_estimator.h"

#include "opencv2/calib3d.hpp"
#include <iostream>

TwoViewRelativePoseEstimator::TwoViewRelativePoseEstimator(const cv::Matx33d& K, double max_epipolar_distance)
    : K_{K}
    , max_epipolar_distance_{max_epipolar_distance}
{ }

RelativePoseEstimate TwoViewRelativePoseEstimator::estimate(const FrameToFrameCorrespondences& corr)
{
  // Set a minimum required number of points,
  // here 3 times the theoretical minimum.
  constexpr size_t min_number_points = 3*5;

  // Check that we have enough points.
  if (corr.size() < min_number_points)
  {
    return {};
  }

  // Get references to 2d-2d point correspondences.
  const auto& points_1 = corr.points_1();
  const auto& points_2 = corr.points_2();

  // Todo 2: Use cv::findEssentialMat() to get an inlier mask for the correspondences. Use max_epipolar_distance_!
  // Find inliers with the 5-point algorithm.
  constexpr double p = 0.99;
  std::vector<unsigned char> inliers;

  // Extract inlier correspondences by using inlier mask.
  std::vector<cv::Point2f> inlier_points_1;
  std::vector<cv::Point2f> inlier_points_2;

  const auto& indices_1 = corr.point_index_1();
  const auto& indices_2 = corr.point_index_2();
  std::vector<size_t> inlier_indices_1;
  std::vector<size_t> inlier_indices_2;
  for (size_t i=0; i<inliers.size(); ++i)
  {
    if (inliers[i] > 0)
    {
      inlier_points_1.push_back(points_1[i]);
      inlier_points_2.push_back(points_2[i]);
      inlier_indices_1.push_back(indices_1[i]);
      inlier_indices_2.push_back(indices_2[i]);
    }
  }

  // Check that we have enough points.
  if (inlier_points_1.size() < min_number_points)
  {
    return {};
  }

  // Todo 3: Compute the fundamental matrix from the entire inlier set using cv::findFundamentalMat()
  // Compute Fundamental Matrix from all inliers.
  const cv::Matx33d F;

  // Todo 4: Compute the essential matrix from the fundamental matrix.
  // Compute Essential Matrix from Fundamental matrix.
  const cv::Matx33d E;

  // Todo 5: Estimate pose from the essential matrix with cv::recoverPose().
  // Recover pose from Essential Matrix.
  cv::Matx33d R;
  cv::Vec3d t;
  const int num_pass_check = 0; // Use cv::recoverPose to return this!

  // Check that we have enough points.
  if (num_pass_check < static_cast<int>(min_number_points))
  {
    return {};
  }

  // Return estimate.
  FrameToFrameCorrespondences inlier_corr{std::move(inlier_points_1),
                                   std::move(inlier_points_2),
                                   std::move(inlier_indices_1),
                                   std::move(inlier_indices_2)};

  return {R, t, inlier_corr, num_pass_check};
}
