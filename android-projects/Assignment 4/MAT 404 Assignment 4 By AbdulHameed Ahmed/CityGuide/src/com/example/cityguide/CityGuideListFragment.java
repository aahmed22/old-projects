package com.example.cityguide;


import android.app.Activity;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.app.ListFragment;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class CityGuideListFragment extends ListFragment implements FragmentManager.OnBackStackChangedListener {
	
	private static final String DEBUG_TAG = "CityGuideListFragment";
	int mCurPosition = -1;
	boolean mShowTwoFragments;
	
	
	@Override
	public void onActivityCreated(Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		getListView().setChoiceMode(ListView.CHOICE_MODE_SINGLE);
		
		String[] CityGuideList = getResources().getStringArray(R.array.attraction);
		setListAdapter(new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_activated_1, CityGuideList));
		
		View detailsFrame = getActivity().findViewById(R.id.fieldentry);
		mShowTwoFragments = detailsFrame != null && detailsFrame.getVisibility() == View.VISIBLE;
		
		if (savedInstanceState != null)
		{
			mCurPosition = savedInstanceState.getInt("curChoice", 0);
		}
		
		if (mShowTwoFragments == true || mCurPosition != -1)
		{
			viewCityGuideInfo(mCurPosition);
		}
		
		
		getFragmentManager().addOnBackStackChangedListener(this);
	}

	public void onBackStackChanged() 
	{
		// update position
		CityGuideWebViewFragment details = (CityGuideWebViewFragment) getFragmentManager()
				.findFragmentById(R.id.fieldentry);
		if (details != null) 
		{
			mCurPosition = details.getShownIndex();
			getListView().setItemChecked(mCurPosition, true);
		}
		
		if (!mShowTwoFragments)
		{
			viewCityGuideInfo(mCurPosition);
		}
	}
	
	@Override
	public void onSaveInstanceState(Bundle outState) 
	{
		super.onSaveInstanceState(outState);
		outState.putInt("curChoice", mCurPosition);
	}
	
	@Override
	public void onListItemClick(ListView l, View v, int position, long id) {
		viewCityGuideInfo(position);
	}
	
	void viewCityGuideInfo(int index)
	{
		mCurPosition = index;
		if (mShowTwoFragments == true)
		{
			CityGuideWebViewFragment details = (CityGuideWebViewFragment) getFragmentManager().findFragmentById(R.id.fieldentry);
			if (details == null || details.getShownIndex() != index)
			{
				CityGuideWebViewFragment newDetails = CityGuideWebViewFragment.newInstance(index);
				FragmentManager fm = getFragmentManager();
				FragmentTransaction ft = fm.beginTransaction();
				ft.replace(R.id.fieldentry, newDetails);
				
				if (index != -1)
				{
					String[] CityGuideList = getResources().getStringArray(R.array.attraction);
					String strBackStackTagName = CityGuideList[index];
					ft.addToBackStack(strBackStackTagName);
				}
				ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE);
				ft.commit();
			}	
		}
		else
		{
			Intent intent = new Intent();
			intent.setClass(getActivity(), MainLand.class);
			intent.putExtra("index", index);
			startActivity(intent);
		}
	}
	
	
	@Override
	public void onAttach(Activity activity) {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onAttach()");
		super.onAttach(activity);
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onCreate()");
		super.onCreate(savedInstanceState);
	}

	@Override
	public void onDestroy() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onDestroy()");
		super.onDestroy();
	}

	@Override
	public void onDetach() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onDetach()");
		super.onDetach();
	}

	@Override
	public void onPause() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onPause()");
		super.onPause();
	}

	@Override
	public void onResume() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onResume(): "
				+ mCurPosition);
		super.onResume();
	}

	@Override
	public void onStart() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onStart()");
		super.onStart();
	}

	@Override
	public void onStop() {
		Log.d(DEBUG_TAG, "FRAGMENT LIFECYCLE EVENT: onStop()");
		super.onStop();
	}
}
