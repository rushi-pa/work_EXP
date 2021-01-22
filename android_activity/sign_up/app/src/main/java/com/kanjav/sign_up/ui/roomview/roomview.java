package com.kanjav.sign_up.ui.roomview;

import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.content.Context;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.kanjav.sign_up.R;
import com.kanjav.sign_up.ui.home.HomeFragment;

import java.util.ArrayList;

public class roomview extends Fragment {

//    private BarGraphViewModel mViewModel;
//
//    public static roomview newInstance() {
//        return new roomview();
//    }
//
//    @Override
//    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
//                             @Nullable Bundle savedInstanceState) {
//        return inflater.inflate(R.layout.bar_graph_fragment, container, false);
//    }
//
//    @Override
//    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
//        super.onActivityCreated(savedInstanceState);
//        mViewModel = ViewModelProviders.of(this).get(BarGraphViewModel.class);
//        // TODO: Use the ViewModel
//    }
private TextView mTextViewEmpty;
    private ProgressBar mProgressBarLoading;
    private ImageView mImageViewEmpty;
    private RecyclerView mRecyclerView;
    private ListAdapter mListadapter;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.bar_graph_fragment, container, false);

        mRecyclerView = (RecyclerView) view.findViewById(R.id.recyclerView);


        final LinearLayoutManager layoutManager = new LinearLayoutManager(getActivity());
        layoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        mRecyclerView.setLayoutManager(layoutManager);

        ArrayList data = new ArrayList<DataNote>();
        for (int i = 0; i < DataNoteIInformation.imageIDArray.length; i++) {
            data.add(
                    new DataNote
                            (
                                    DataNoteIInformation.imageIDArray[i],
                                    DataNoteIInformation.statLabelNameArray[i]

                            ));
        }

        mListadapter = new ListAdapter(data);
        mRecyclerView.setAdapter(mListadapter);

        return view;
    }

    public class ListAdapter extends RecyclerView.Adapter<ListAdapter.ViewHolder> {
        private ArrayList<DataNote> dataList;
        Fragment fragment;

        public ListAdapter(ArrayList<DataNote> data) {
            this.dataList = data;
        }

        public class ViewHolder extends RecyclerView.ViewHolder {
            ImageView textViewText;
            TextView textViewComment;

            public ViewHolder(View itemView) {
                super(itemView);
                this.textViewText = (ImageView) itemView.findViewById(R.id.myImage); //error.
                this.textViewComment = (TextView) itemView.findViewById(R.id.comment_xml);
            }
        }

        @Override
        public ListAdapter.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.recyclerview_item, parent, false);
            ViewHolder viewHolder = new ViewHolder(view);
            return viewHolder;
        }

        @Override
        public void onBindViewHolder(ListAdapter.ViewHolder holder, final int position) {
            final Fragment[] myfragment = new Fragment[1];
            final Context thisContext;
            thisContext = getContext();

            holder.textViewText.setImageResource(dataList.get(position).getstatImageValue());
            holder.textViewComment.setText(dataList.get(position).getstatLabelName());
            holder.itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    HomeFragment f2;
                    String b = dataList.get(position).getstatLabelName();
                    System.out.println(b);
                    //String a = userName.getText().toString();
                    Bundle bundle = new Bundle();
                    bundle.putString("LabelName", b);
                    //secondFragment f2 = new secondFragment();

                    switch (position) {
                        case 1:
                            Toast.makeText(getActivity(), "Item " + b + " is clicked.", Toast.LENGTH_SHORT).show();
                            f2 = new HomeFragment();
                            break;
                        case 0:
                            Toast.makeText(getActivity(), "Item " + b + " is clicked.", Toast.LENGTH_SHORT).show();
                            f2 = new HomeFragment();
                            break;
                        default:
                            Toast.makeText(getActivity(), "Item " + b + " is clicked.", Toast.LENGTH_SHORT).show();
                            f2 = new HomeFragment();
                            break;
                    }
                    f2.setArguments(bundle);



                    FragmentManager myFM = getActivity().getSupportFragmentManager();
                    FragmentTransaction myFT = myFM.beginTransaction();
                    myFT.replace(R.id.nav_host_fragment, f2);
                    myFT.commit();


                    //   myfragment[0] = new secondFragment();
                    //loadFragment(myfragment[0], thisContext);

                }
            });
        }

        @Override
        public int getItemCount() {
            return dataList.size();
        }
    }
}