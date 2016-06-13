package name.zzzzzzzzzzz.suanming;

import android.app.Activity;
import android.os.Bundle;
import android.widget.EditText;
import android.content.Intent;
import android.widget.Button;
import android.view.View.OnClickListener;
import android.view.View;

public class Edit extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.edit);
		Bundle b = getIntent().getExtras();
		final EditText text_ = (EditText)this.findViewById(R.id.editText);
		text_.setText(b.getString("s"));
		final String js_ = b.getString("js");

		Button save_and_use = (Button)this.findViewById(R.id.button);
		save_and_use.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				Intent i = new Intent();
				i.putExtra("s", text_.getText().toString());
				i.putExtra("js", js_);
				setResult(RESULT_OK, i);
				finish();
			}
		});

		Button cancel = (Button)this.findViewById(R.id.button2);
		cancel.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				setResult(RESULT_CANCELED);
				finish();
			}
		});
	}
}
