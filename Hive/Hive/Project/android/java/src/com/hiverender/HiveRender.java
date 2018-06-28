package com.hiverender;
import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class HiveRender implements GLSurfaceView.Renderer{

	
	@Override
	public void onDrawFrame(GL10 arg0) {
		// TODO Auto-generated method stub
		JNI.nativeRender();
	}

	@Override
	public void onSurfaceChanged(GL10 arg0, int arg1, int arg2) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onSurfaceCreated(GL10 arg0, EGLConfig arg1) {
		// TODO Auto-generated method stub
		JNI.nativeInit(100, 100);
	}

}
