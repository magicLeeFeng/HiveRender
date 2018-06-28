package com.hiverender;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.FrameLayout;

public class MainActivity extends Activity {

	public HiveGLSurfaceView mSurfaceView;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.init();
    }
	
	//载入so文件 
    static {
        System.loadLibrary("hiverender");
    }
    
    public void init()
    {
    	 FrameLayout framelayout = new FrameLayout(this);  
         
         mSurfaceView = new HiveGLSurfaceView(this);
         this.mSurfaceView.setHiveRender(new HiveRender());
         framelayout.addView(this.mSurfaceView);
         
         this.setContentView(framelayout);
    }
}
