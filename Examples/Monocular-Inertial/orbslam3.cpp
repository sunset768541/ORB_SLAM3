#include <jni.h>
#include <string>


#include <opencv2/opencv.hpp>



#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
#include <ctime>
#include <sstream>

#include<opencv2/core/core.hpp>
#include<System.h>
#include "ImuTypes.h"

#define  LOG_TAG    "ImageSlam3"
using namespace std;
ORB_SLAM3::System* SLAM = nullptr;
extern "C" JNIEXPORT jstring JNICALL
Java_com_cmic_ar_OrbSlam3NativeBridge_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "NDK So库加载成功";
    SLAM = new ORB_SLAM3::System("/home/slam/ROSSLAM/ORB_SLAM3/Vocabulary/ORBvoc.txt","/home/slam/ROSSLAM/ORB_SLAM3/Pixel86.yaml",ORB_SLAM3::System::IMU_MONOCULAR, true);
    return env->NewStringUTF(hello.c_str());
}
