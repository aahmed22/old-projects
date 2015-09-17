package com.example.abdulhameed_piggybankapp;

import java.text.DecimalFormat;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class Bank extends Activity {
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	double total;
	String choice;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.bank);
		final EditText tquarters = (EditText) findViewById(R.id.btnQuarters);
		final EditText tdimes = (EditText) findViewById(R.id.btnDimes);
		final EditText tnickels = (EditText) findViewById(R.id.btnNickels);
		final EditText tpennies = (EditText) findViewById(R.id.btnPennies);
		final Spinner selection = (Spinner) findViewById(R.id.txtspinner);
		Button cost = (Button) findViewById(R.id.btncalculate);
		final TextView result = (TextView) findViewById(R.id.txtResult);
		cost.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				quarters = Integer.parseInt(tquarters.getText().toString());
				dimes = Integer.parseInt(tdimes.getText().toString());
				nickels = Integer.parseInt(tnickels.getText().toString());
				pennies = Integer.parseInt(tpennies.getText().toString());
				
				quarters *= 0.25;
				dimes *= 0.10;
				nickels *= 0.05;
				pennies *= 0.01;
				
				total = quarters + dimes + nickels + pennies;
				choice = selection.getSelectedItem().toString();
				DecimalFormat currency = new DecimalFormat("$###,###.##");
				result.setText("You are " + choice + " " + currency.format(total));
				}
		});
	}

}
