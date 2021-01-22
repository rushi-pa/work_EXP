package com.kanjav.sign_up.ui.home;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import com.kanjav.sign_up.R;
import com.kanjav.sign_up.sign_in;
import com.google.firebase.auth.FirebaseAuth;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Random;

public class HomeFragment extends Fragment {

//    private HomeViewModel homeViewModel;
//
//    public View onCreateView(@NonNull LayoutInflater inflater,
//                             ViewGroup container, Bundle savedInstanceState) {
//        homeViewModel =
//                ViewModelProviders.of(this).get(HomeViewModel.class);
//        View root = inflater.inflate(R.layout.fragment_home, container, false);
//        final TextView textView = root.findViewById(R.id.text_home);
//        homeViewModel.getText().observe(getViewLifecycleOwner(), new Observer<String>() {
//            @Override
//            public void onChanged(@Nullable String s) {
//                textView.setText(s);
//            }
//        });
//        return root;
//    }
//
//
//    @Override
//    public void onCreate(@Nullable Bundle savedInstanceState) {
//        setHasOptionsMenu(true);
//        super.onCreate(savedInstanceState);
//
//    }
//
//
//
//
//    @Override
//
//    public boolean onOptionsItemSelected(MenuItem item) {
//        switch (item.getItemId()) {
//            case R.id.action_settings:
//                //just to test if this works.
//                final Intent intent = new Intent(getContext(), SettingsActivity.class);
//                startActivity(intent);
//                return true;
//
//
//        }
//        return super.onOptionsItemSelected(item);
//    }
private TextView dateTimeDisplay;
    private ImageView logout;
    private Calendar calendar;
    private SimpleDateFormat dateFormat;
    private String date;
    private TextView temp;
    int random;
    String myRan;
    TextView statLabelName_TextView;
    Button todayBtn, weekBtn, monthBtn, yearBtn;
    String name;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        statLabelName_TextView = view.findViewById(R.id.enviroLabelText);
        Bundle bundle = getArguments();

        if(bundle != null){
            name = bundle.getString("LabelName");
            statLabelName_TextView.setText(name);

        }
        logout = (ImageView) view.findViewById(R.id.signOutArrow);

        todayBtn = view.findViewById(R.id.buttonToday);
        weekBtn = view.findViewById(R.id.buttonWeek);
        monthBtn = view.findViewById(R.id.buttonMonth);
        yearBtn = view.findViewById(R.id.buttonYear);



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

        logout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                FirebaseAuth.getInstance().signOut();
                Intent i = new Intent(getActivity(), sign_in.class);
                startActivity(i);
                ((Activity) getActivity()).overridePendingTransition(0, 0);

            }
        });



        dateTimeDisplay = (TextView)  view.findViewById(R.id.today_date);
        calendar = Calendar.getInstance();
        dateFormat = new SimpleDateFormat("MMM dd");
        date = (String) dateFormat.format(calendar.getTime());
        dateTimeDisplay.setText(date);

        temp = (TextView)  view.findViewById(R.id.temp);
        random = new Random().nextInt(28) -5;
        myRan=Integer.toString(random);
        myRan = myRan + " \u00B0C";
        temp.setText(myRan);

        return view;
    }
}