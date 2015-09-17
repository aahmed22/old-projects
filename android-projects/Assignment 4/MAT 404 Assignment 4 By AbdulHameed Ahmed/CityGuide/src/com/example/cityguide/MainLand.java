package com.example.cityguide;

import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.res.Configuration;
import android.os.Bundle;

public class MainLand extends Activity {
  @Override
  public void onCreate(Bundle savedInstanceState)
  {
	  super.onCreate(savedInstanceState);
	  
	  if (getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE)
	  {
		  finish();
		  return;
	  }
	  if (savedInstanceState == null)
	  {
		  CityGuideWebViewFragment details = new CityGuideWebViewFragment();
		  details.setArguments(getIntent().getExtras());
		  
		  FragmentManager fm = getFragmentManager();
		  FragmentTransaction ft = fm.beginTransaction();
		  ft.add(android.R.id.content, details);
		  ft.commit();
	  }
	  
  }
}
