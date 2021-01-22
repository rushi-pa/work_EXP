package com.kanjav.sign_up;

public class DataNote {
    int statImageValue;
    String statLabelName;

    public DataNote(int myInt, String comment)
    {
        this.statImageValue = myInt;
        this.statLabelName = comment;

    }

    public int getstatImageValue()
    {
        return statImageValue;
    }

    public String getstatLabelName()
    {
        return statLabelName;
    }



}
