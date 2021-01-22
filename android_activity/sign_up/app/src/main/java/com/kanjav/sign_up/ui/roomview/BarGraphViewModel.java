package com.kanjav.sign_up.ui.roomview;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.lifecycle.ViewModel;

import com.kanjav.sign_up.R;

public class BarGraphViewModel extends ViewModel {
    // TODO: Implement the ViewModel
    private BarGraphViewModel barGraphViewModel;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState){
//        barGraphViewModel =
//                ViewModelProviders.of(this).get(barGraphViewModel.class);
        View root = inflater.inflate(R.layout.bar_graph_fragment, container, false);

        return root;
    }
}