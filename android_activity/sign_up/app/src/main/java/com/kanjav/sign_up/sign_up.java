package com.kanjav.sign_up;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.FirebaseDatabase;


public class sign_up extends AppCompatActivity implements View.OnClickListener {
    private FirebaseAuth mAuth;
    private ImageView imageView;
    private Button signUpBtn;
    private ProgressBar progressBar;
    private EditText editTextUserName, editTextEmail, editTextPassword;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        mAuth = FirebaseAuth.getInstance();
        signUpBtn = (Button)findViewById(R.id.signupbtn);
        signUpBtn.setOnClickListener(this);

        imageView = (ImageView) findViewById(R.id.logo);

        editTextUserName= (EditText) findViewById(R.id.editTextUserNameSignUp);
        editTextEmail = (EditText) findViewById(R.id.editTextEmailSignUp);
        editTextPassword = (EditText) findViewById(R.id.editTextPasswordSignUp);

        progressBar = (ProgressBar) findViewById(R.id.progressBarSignUp);


    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.logo:
                startActivity(new Intent(this, sign_in.class));
                break;
            case R.id.signupbtn:
                registerUser();

                break;
        }
    }

    private void registerUser() {
        final String email = editTextEmail.getText().toString().trim();
        final String username = editTextUserName.getText().toString().trim();
        String password = editTextPassword.getText().toString();


        if (username.isEmpty()) {
            editTextUserName.setError("Username is required");
            editTextUserName.requestFocus();
            return;
        }
        if (email.isEmpty()) {
            editTextUserName.setError("Email is required");
            editTextUserName.requestFocus();
            return;
        }
        if (password.isEmpty()) {
            editTextUserName.setError("Password is required");
            editTextUserName.requestFocus();
            return;
        }

        if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
            editTextEmail.setError("Please provide a valid email!");
            editTextEmail.requestFocus();
            return;
        }

        if (password.length() < 8) {
            editTextPassword.setError("Minimum password length should be 8 characters!");
            editTextPassword.requestFocus();
            return;
        }

        progressBar.setVisibility(View.VISIBLE);
        mAuth.createUserWithEmailAndPassword(editTextEmail.getText().toString().trim(),editTextPassword.getText().toString())
                .addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()) {
                            User user = new User(email,username);
                            FirebaseDatabase fdb = FirebaseDatabase.getInstance();

                            FirebaseDatabase.getInstance().getReference("Users")
                                    .child(FirebaseAuth.getInstance().getCurrentUser().getUid())
                                    .setValue(user)
                                    .addOnCompleteListener(new OnCompleteListener<Void>(){

                                        @Override
                                        public void onComplete(@NonNull Task<Void> task) {
                                            if (task.isSuccessful()) {
                                                Toast.makeText(sign_up.this, "User has been register successfully!", Toast.LENGTH_LONG).show();
                                                startActivity(new Intent(sign_up.this, sign_in.class));
                                            }else{
                                                Toast.makeText(sign_up.this,"Failed to register! try Again!", Toast.LENGTH_LONG).show();
                                            }
                                            progressBar.setVisibility(View.GONE);
                                        }
                                    });
                        } else {

                            Toast.makeText(sign_up.this, "Authentication failed.",
                                    Toast.LENGTH_SHORT).show();
                            //updateUI(null);
                        }
                    }
                });
    }
}