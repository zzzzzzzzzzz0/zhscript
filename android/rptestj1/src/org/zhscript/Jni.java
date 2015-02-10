package org.zhscript;

import android.content.Context;
import android.content.res.AssetManager;
import android.util.Log;
import android.webkit.JavascriptInterface;
import android.widget.Toast;

public class Jni {
	public final String log_tag_ = "zhscript";
    static {
        System.loadLibrary("zhscript");  
    }

    private Context c_;
	
	public Jni(String cmdline, String suidao, AssetManager am, Context c) {
		c_ = c;
		int err = init(cmdline, suidao, this, am, log_tag_);
		if(err != 0) {
			Log.e(log_tag_, "err" + err);
		}
	}
	
	public String suidao__(String[] s) {
		StringBuffer sb = new StringBuffer();
		if(s != null) {
			for(int i = 0; i < s.length; i++) {
				if(i > 0)
					sb.append("--");
				sb.append(s[i]);
			}
		}
		Log.d(log_tag_, sb.toString());
		return "";
	}
	
	private native int init(String cmdline, String suidao, Jni thiz2, AssetManager am, String log_tag_);
    private native int jieshi(String[] s, Result r, Jni thiz2);
	
	@JavascriptInterface
	final public String _(String ...s) {
		Result r = new Result();
		
		jieshi(s, r, this);
		if(r.end_ == 1) {
			System.exit(0);
			return null;
		}
		
		/*JSONObject o = new JSONObject();
		try {
			if(jieshi(s, r) != 0) {
				o.put("err", true);
				o.put("err2", r.err2_);
			} else {
				o.put("err", false);
				o.put("ret", r.ret_);
			}
		} catch(Exception e) {
			Log.e(log_tag_, e.getLocalizedMessage());
		}
		return o.toString();*/
		
		if(r.err_ != 0) {
			Log.e(log_tag_, r.err2_);
			showmsg(r.err2_);
		}
		return r.ret_;
	}
	
	public void showmsg(String s) {
		Toast.makeText(c_, s, Toast.LENGTH_LONG).show();
	}
	
	@JavascriptInterface
	final public String v(String... s) {
		return v__(s);
	}
	
	protected String v__(String... s) {
		return null;
	}
}
