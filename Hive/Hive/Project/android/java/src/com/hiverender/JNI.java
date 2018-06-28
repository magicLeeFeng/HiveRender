package com.hiverender;

public class JNI {

	public static native void nativeInit(final int width,final int height);
	public static native void nativeRender();
}
