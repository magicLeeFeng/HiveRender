package com.hiverender;

import android.app.Activity;
import android.os.Bundle;
import android.widget.FrameLayout;

public class HiveActivity extends Activity {
	
	public HiveGLSurfaceView mSurfaceView;
	
	protected void onCreate(final Bundle savedInstanceState) {  
	    super.onCreate(savedInstanceState);  
	    this.init();
	}
	
	//载入so文件 
    static {
        System.loadLibrary("hiverender");
    }
    
    public void init()
    {
//    	 FrameLayout framelayout = new FrameLayout(this);  
//         
//         mSurfaceView = new HiveGLSurfaceView(this);
//         framelayout.addView(this.mSurfaceView);
//         
//         this.setContentView(framelayout);
    }
	
}
