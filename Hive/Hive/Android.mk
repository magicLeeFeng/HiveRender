
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hiveRender_shaderd_static

LOCAL_MODULE_FILENAME := libhiverenderinternal

LOCAL_SRC_FILES := \
Math/ARBBox.cpp \
Math/ARMatrix.cpp \
Math/ARPoint.cpp \
Math/ARRay.cpp \
Math/ARRayDifferential.cpp \
Math/ARVector.cpp \
Render/ARCamera.cpp \
Render/ARMaterial.cpp \
Render/ARMesh.cpp \
Render/ARMeshShape.cpp \
Render/ARNormal.cpp \
Render/ARScene.cpp \
Render/Preset/EmptyMaterial.cpp \
Render/Preset/PolygonPlane.cpp \
Base/Director.cpp \
Base/ManagerMaterial.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH) \


include $(BUILD_STATIC_LIBRARY)

