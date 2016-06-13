package name.zzzzzzzzzzz.suanming;

import org.zhscript.Jni;

import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.WindowManager;
import android.webkit.JsResult;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import java.io.InputStream;
import org.apache.http.util.EncodingUtils;

@SuppressLint({ "SetJavaScriptEnabled", "JavascriptInterface" })
public class Main extends Activity {
	static {
		System.loadLibrary("calcu");
	}

	private Jni jni_;
	
	private final int html_msg_ = 1,
						go_msg_ = 2,
						edit_msg_ = 3;
	@SuppressLint("HandlerLeak")
	private Handler handler_ = new Handler() {
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case html_msg_:
				html__(msg.obj.toString());
				break;
			case go_msg_:
				go__(msg.obj.toString());
				break;
			case edit_msg_:
				intent__('e', msg.obj);
				break;
			}
			super.handleMessage(msg);
		}
	};
	private void send_msg(int i, Object o) {
		Message msg = new Message();
		msg.what = i;
		msg.obj = o;
		handler_.sendMessage(msg);
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_PAN);
		
		wv_ = (WebView) this.findViewById(R.id.webView1);
		wv_.setWebViewClient(new wvc___());
		wv_.setWebChromeClient(new wcc___());
		
		WebSettings ws = wv_.getSettings();
		ws.setJavaScriptEnabled(true);
		ws.setSupportZoom(true);
		ws.setBuiltInZoomControls(true);
		
		wv_.addJavascriptInterface(
		jni_ = new Jni("-S syn-zh -E err-zh", "我的", getAssets(), this) {
			@Override
			protected String v__(String... s) {
				return super.v__(s);
			}
			
			@Override
			public String suidao__(String[] s) {
				switch(s.length) {
				case 3:
					switch(s[0]) {
					case "编辑":
						send_msg(edit_msg_, s);
						return "";
					}
					break;
				case 2:
					switch(s[0]) {
					case "访问":
						send_msg(go_msg_, s[1]);
						return "";
					case "内容":
						send_msg(html_msg_, s[1]);
						return "";
					case "文件":
						String result = "";
						try {
							InputStream is = getResources().getAssets().open(s[1]);
							byte[]  buf = new byte[is.available()];
							is.read(buf);
							result = EncodingUtils.getString(buf, "UTF-8");
						} catch (Exception e) {
							e.printStackTrace();
						}
						return result;
					}
					break;
				case 1:
					switch(s[0]) {
					case "who":
						return this.getClass().getName();
					}
					break;
				}
				return super.suidao__(s);
			}
		}, "z$");

		/*wv_.setOnTouchListener(new OnTouchListener()
		{
			@Override
			public boolean onTouch(View arg0, MotionEvent arg1) {
				wv_.requestFocus();
				return false;
			}
		});*/
		//wv_.requestFocus(View.FOCUS_DOWN);
		wv_.setOnTouchListener(new View.OnTouchListener() {
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				switch (event.getAction()) {
				case MotionEvent.ACTION_DOWN:
				case MotionEvent.ACTION_UP:
					if (!v.hasFocus()) {
						v.requestFocus();
					}
					break;
				}
				return false;
			}
		});

		go__("index.html");
	}

	private class wvc___ extends WebViewClient {
		@Override
		public boolean shouldOverrideUrlLoading(WebView view, String url) {
			if(url.startsWith("mailto:")) {
				Intent data = new Intent(Intent.ACTION_SENDTO);    
				data.setData(Uri.parse(url));    
				data.putExtra(Intent.EXTRA_SUBJECT, getString(R.string.app_name));
				data.putExtra(Intent.EXTRA_TEXT, getString(R.string.hello_world)); 
				try {
					startActivity(data);
				} catch(Exception e) {
					jni_.showmsg(e.getLocalizedMessage());
				}
			} else
				view.loadUrl(url);
			return true;
		}
	}
	
	private class wcc___ extends WebChromeClient {
		@Override
		public boolean onJsAlert(WebView view, String url, String message,
				JsResult result) {
			return super.onJsAlert(view, url, message, result);
		}
	}

	private WebView wv_;
	private void go__(String url) {
		if(url.indexOf("://") < 0)
			url = "file:///android_asset/" + url;
		wv_.loadUrl(url);
	}
	private void js__(String s) {
		wv_.loadUrl("javascript:" + s);
	}
	private void html__(String data) {
		wv_.loadDataWithBaseURL(null, data, null, "utf-8", null);
	}
	
	private void intent__(char c, Object o) {
		Intent i = null;
		switch(c) {
		case 'e':
			i = new Intent(this, Edit.class);
			Bundle b = new Bundle();
			String[] s = (String[])o;
			b.putString("s", s[1]);
			b.putString("js", s[2]);
			i.putExtras(b);
			break;
		}
		if(i != null) {
			//startActivity(i);
			startActivityForResult(i, 0);
		}
	}

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		int iid = item.getItemId(), i = 0;
		switch(iid) {
		case R.id.action_settings:
			i = R.string.action_settings;
			break;
		case R.id.go_about:
			i = R.string.go_about;
			break;
		case R.id.go_index:
			i = R.string.go_index;
			break;
		}
		if(i > 0) {
			jni_._(getString(i));
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if ((keyCode == KeyEvent.KEYCODE_BACK)) {
			if(wv_.canGoBack())
				wv_.goBack();
			else
				this.openOptionsMenu();
			return true;
		}
		return super.onKeyDown(keyCode, event);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		switch (resultCode) {
		case RESULT_OK:
			Bundle b = data.getExtras();
			String s = b.getString("s")
					.replace("\"", "\\\\\"")
					.replace("\n", "\\\\n");
			js__(b.getString("js").replaceAll("@@", s));
			break;
		}
	}
}
