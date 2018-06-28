package com.hiverender;

import android.content.Context;
import android.opengl.GLSurfaceView;

public class HiveGLSurfaceView extends GLSurfaceView{

	public HiveRender mHiveRender = null;
	public HiveGLSurfaceView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		setEGLContextClientVersion(2); // This is the important line
	}
	
	public void setHiveRender(final HiveRender renderer)
	{
		this.setRenderer(renderer);
	}
	
	
}
