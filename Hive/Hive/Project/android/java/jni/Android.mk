LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := hiveRender_shaderd
LOCAL_MODULE_FILENAME := libhiverender



LOCAL_SRC_FILES := \
../../../../Math/ARBBox.cpp \
../../../../Math/ARMatrix.cpp \
../../../../Math/ARPoint.cpp \
../../../../Math/ARRay.cpp \
../../../../Math/ARRayDifferential.cpp \
../../../../Math/ARVector.cpp \
../../../../Render/ARCamera.cpp \
../../../../Render/ARMaterial.cpp \
../../../../Render/ARMesh.cpp \
../../../../Render/ARMeshShape.cpp \
../../../../Render/ARNormal.cpp \
../../../../Render/ARScene.cpp \
../../../../Render/Preset/EmptyMaterial.cpp \
../../../../Render/Preset/PolygonPlane.cpp \
../../../../Base/Director.cpp \
../../../../Base/ManagerMaterial.cpp \
../../../../../../Class/AppDelegate.cpp \
cpp/com_hiverender_JNI.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH) \
					$(LOCAL_PATH)/../../../../ \
					$(LOCAL_PATH)/../../../../../../Class \
                    $(LOCAL_PATH)/cpp

#LOCAL_STATIC_LIBRARIES := hiveRender_shaderd_static
LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lGLESv3

include $(BUILD_SHARED_LIBRARY)