#ifndef RECORD_TEST_HELPERS_H
#define RECORD_TEST_HELPERS_H

#include <utcommon.h>
#include <k4a/k4a.h>

static const char *const format_names[] = { "K4A_IMAGE_FORMAT_COLOR_MJPG", "K4A_IMAGE_FORMAT_COLOR_NV12",
                                            "K4A_IMAGE_FORMAT_COLOR_YUY2", "K4A_IMAGE_FORMAT_COLOR_BGRA32",
                                            "K4A_IMAGE_FORMAT_DEPTH16",    "K4A_IMAGE_FORMAT_IR16",
                                            "K4A_IMAGE_FORMAT_CUSTOM" };
static const char *const resolution_names[] = { "K4A_COLOR_RESOLUTION_OFF",   "K4A_COLOR_RESOLUTION_720P",
                                                "K4A_COLOR_RESOLUTION_1080P", "K4A_COLOR_RESOLUTION_1440P",
                                                "K4A_COLOR_RESOLUTION_1536P", "K4A_COLOR_RESOLUTION_2160P",
                                                "K4A_COLOR_RESOLUTION_3072P" };
static const char *const depth_names[] = { "K4A_DEPTH_MODE_OFF",           "K4A_DEPTH_MODE_NFOV_2X2BINNED",
                                           "K4A_DEPTH_MODE_NFOV_UNBINNED", "K4A_DEPTH_MODE_WFOV_2X2BINNED",
                                           "K4A_DEPTH_MODE_WFOV_UNBINNED", "K4A_DEPTH_MODE_PASSIVE_IR" };
static const char *const fps_names[] = { "K4A_FRAMES_PER_SECOND_5",
                                         "K4A_FRAMES_PER_SECOND_15",
                                         "K4A_FRAMES_PER_SECOND_30" };

k4a_capture_t create_test_capture(uint64_t timestamp_us[3],
                                  k4a_image_format_t color_format,
                                  k4a_color_resolution_t resolution,
                                  k4a_depth_mode_t mode);
bool validate_test_capture(k4a_capture_t capture,
                           uint64_t timestamp_us[3],
                           k4a_image_format_t color_format,
                           k4a_color_resolution_t resolution,
                           k4a_depth_mode_t mode);
k4a_image_t
create_test_image(uint64_t timestamp_us, k4a_image_format_t format, uint32_t width, uint32_t height, uint32_t stride);
bool validate_test_image(k4a_image_t image,
                         uint64_t timestamp_us,
                         k4a_image_format_t format,
                         uint32_t width,
                         uint32_t height,
                         uint32_t stride);
k4a_imu_sample_t create_test_imu_sample(uint64_t timestamp_us);
bool validate_imu_sample(k4a_imu_sample_t imu_sample, uint64_t timestamp_us);

class SampleRecordings : public ::testing::Environment
{
public:
    ~SampleRecordings() override {}

protected:
    void SetUp() override;
    void TearDown() override;
};

#endif /* RECORD_TEST_HELPERS_H */