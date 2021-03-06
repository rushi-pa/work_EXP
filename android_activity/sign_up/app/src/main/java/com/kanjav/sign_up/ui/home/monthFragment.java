package com.kanjav.sign_up.ui.home;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.kanjav.sign_up.R;

/**
 * A simple {@link Fragment} subclass.
 * create an instance of this fragment.
 */
public class monthFragment extends Fragment {
    TextView statLabelName_TextView;
    Button todayBtn, weekBtn, monthBtn, yearBtn;
    String name;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view2= inflater.inflate(R.layout.fragment_month, container, false);

        statLabelName_TextView = view2.findViewById(R.id.labeltodayButton);
        Bundle bundle = getArguments();

        if(bundle != null){
            name = bundle.getString("LabelName");
            statLabelName_TextView.setText(name);
        }

        todayBtn = view2.findViewById(R.id.buttonToday);
        weekBtn = view2.findViewById(R.id.buttonWeek);
        monthBtn = view2.findViewById(R.id.buttonMonth);
        yearBtn = view2.findViewById(R.id.buttonYear);



        todayBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString("LabelName", name);
                HomeFragment transferFragment = new HomeFragment();
                transferFragment.setArguments(bundle);

                FragmentManager myFM = getActivity().getSupportFragmentManager();
                FragmentTransaction myFT = myFM.beginTransaction();
                myFT.replace(R.id.nav_host_fragment,transferFragment);
                myFT.commit();
            }
        });

        weekBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString("LabelName", name);
                weekFragment transferFragment = new weekFragment();
                transferFragment.setArguments(bundle);

                FragmentManager myFM = getActivity().getSupportFragmentManager();
                FragmentTransaction myFT = myFM.beginTransaction();
                myFT.replace(R.id.nav_host_fragment,transferFragment);
                myFT.commit();
            }
        });

        monthBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString("LabelName", name);
                monthFragment transferFragment = new monthFragment();
                transferFragment.setArguments(bundle);

                FragmentManager myFM = getActivity().getSupportFragmentManager();
                FragmentTransaction myFT = myFM.beginTransaction();
                myFT.replace(R.id.nav_host_fragment,transferFragment);
                myFT.commit();
            }
        });

        yearBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Bundle bundle = new Bundle();
                bundle.putString("LabelName", name);
                yearFragment transferFragment = new yearFragment();
                transferFragment.setArguments(bundle);

                FragmentManager myFM = getActivity().getSupportFragmentManager();
                FragmentTransaction myFT = myFM.beginTransaction();
                myFT.replace(R.id.nav_host_fragment,transferFragment);
                myFT.commit();
            }
        });

        return view2;
    }
}