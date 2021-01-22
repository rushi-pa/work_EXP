package com.kanjav.sign_up;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.auth.api.Auth;
import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInClient;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.common.api.ApiException;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.android.material.snackbar.Snackbar;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.auth.GoogleAuthProvider;

public class sign_in extends AppCompatActivity implements View.OnClickListener {

    private FirebaseAuth mAuth;

    private ImageView imageView;
    private Button signInBtn, signInWithGoogle;
    private TextView forgotPassword, createAccount;
    private EditText editTextUserName, editTextEmail, editTextPassword;
    private ProgressBar progressBar;


    private static final String TAG = "GoogleActivity";
    private static final int RC_SIGN_IN = 9001;

    // [START declare_auth]

    // [END declare_auth]

    private GoogleSignInClient mGoogleSignInClient;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_in);
        signInBtn = (Button)findViewById(R.id.signInBtn);

        signInWithGoogle = (Button)findViewById(R.id.signInWithGoogle);
        signInWithGoogle.setOnClickListener(this);

        mAuth = FirebaseAuth.getInstance();

        forgotPassword = (TextView) findViewById(R.id.forgotPassTextView);
        forgotPassword.setOnClickListener(this);

        createAccount = (TextView) findViewById(R.id.createAccountBtn);
        createAccount.setOnClickListener(this);
        signInBtn.setOnClickListener(this);
        imageView = (ImageView) findViewById(R.id.logo);


        editTextEmail = (EditText) findViewById(R.id.editTextEmailSignIn);
        editTextPassword = (EditText) findViewById(R.id.editTextPasswordSignIn);

        progressBar = (ProgressBar) findViewById(R.id.progressBarSignIn);

        GoogleSignInOptions gso = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestIdToken(getString(R.string.default_web_client_id))
                .requestEmail()
                .build();
        mGoogleSignInClient = GoogleSignIn.getClient(this,gso);
//        GoogleApiClient.Builder mGoogleApiClient = new GoogleApiClient.Builder(this)
//                .enableAutoManage(this /* FragmentActivity */, (GoogleApiClient.OnConnectionFailedListener) this/* OnConnectionFailedListener */)
//                .addApi(Auth.GOOGLE_SIGN_IN_API,gso);


        MobileAds.initialize(this, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {
            }
        });
//        AdView adView = new AdView(this);
//
//        adView.setAdSize(AdSize.BANNER);
//
//        adView.setAdUnitId("cca-app-pub-5093527725329656/8312343946");

        AdView adView = findViewById(R.id.adView);
        AdRequest adRequest = new AdRequest.Builder()
                .addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
                .build();
        adView.loadAd(adRequest);



    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.createAccountBtn:
                startActivity(new Intent(this, sign_up.class));
                break;
            case R.id.signInBtn:
                userLogin();
                break;
            case R.id.signInWithGoogle:
                signIn();
                break;
            case R.id.forgotPassTextView:
                startActivity(new Intent(this, forgotPassword.class));
                break;
        }
    }

    private void signIn() {
        Intent signInIntent = mGoogleSignInClient.getSignInIntent();
        startActivityForResult(signInIntent, RC_SIGN_IN);
    }
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        // Result returned from launching the Intent from GoogleSignInApi.getSignInIntent(...);
        if (requestCode == RC_SIGN_IN) {
            Task<GoogleSignInAccount> task = GoogleSignIn.getSignedInAccountFromIntent(data);
//            Exception exeption = task.getException();
//            if (task.isSuccessful()) {
                try {
                    // Google Sign In was successful, authenticate with Firebase
                    GoogleSignInAccount account = task.getResult(ApiException.class);
                    Log.d(TAG, "firebaseAuthWithGoogle:" + account.getId());
                    firebaseAuthWithGoogle(account.getIdToken());
                } catch (ApiException e) {
                    // Google Sign In failed, update UI appropriately
                    Toast.makeText(this, "Failed to login with google", Toast.LENGTH_SHORT).show();
                    // ...
                }
//            }else {
//                Log.w(TAG, "Google sign in failed", exeption);
//            }
        }
    }

    private void firebaseAuthWithGoogle(String idToken) {
        AuthCredential credential = GoogleAuthProvider.getCredential(idToken, null);
        mAuth.signInWithCredential(credential)
                .addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()) {
                            // Sign in success, update UI with the signed-in user's information
                            Toast.makeText(sign_in.this, "signInWithCredential:success", Toast.LENGTH_SHORT).show();
                            FirebaseUser user = mAuth.getCurrentUser();
                            updateUI(user);
                            startActivity(new Intent(sign_in.this, NavigationActivity.class));

                        } else {
                            // If sign in fails, display a message to the user.
                            Toast.makeText(sign_in.this, "Failed to sign in with google", Toast.LENGTH_SHORT).show();
                        }

                        // ...
                    }
                });
    }
    private void updateUI(FirebaseUser user) {

        if (user != null) {

            editTextEmail.setText(getString(R.string.google_status_fmt, user.getEmail()));
            //mBinding.detail.setText(getString(R.string.firebase_status_fmt, user.getUid()));

        }
    }

    private void userLogin() {
        final String email = editTextEmail.getText().toString();

        final String pass = editTextPassword.getText().toString();

        if (email.isEmpty()){
            editTextEmail.setError("Email is required");
            editTextEmail.requestFocus();
            return;
        }
        if (email.isEmpty()){
            editTextPassword.setError("Password is required");
            editTextPassword.requestFocus();
            return;
        }

        if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()){
            editTextEmail.setError("Please provide a valid email!");
            editTextEmail.requestFocus();
            return;
        }

        if (pass.length() < 8){
            editTextPassword.setError("Minimum password length should be 8 characters!");
            editTextPassword.requestFocus();
            return;
        }

        progressBar.setVisibility(View.VISIBLE);

        mAuth.signInWithEmailAndPassword(editTextEmail.getText().toString().trim(), editTextPassword.getText().toString())
                .addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if (task.isSuccessful()){
                    FirebaseUser user = FirebaseAuth.getInstance().getCurrentUser();
                    if (user.isEmailVerified()) {
                        startActivity(new Intent(sign_in.this, NavigationActivity.class));
                    }else {
                        user.sendEmailVerification();
                        Toast.makeText(sign_in.this, "Please verify your email! Verification link send.", Toast.LENGTH_SHORT).show();
                    }
                }
                else {
                    Toast.makeText(sign_in.this, "Fail to login! please check your credentials", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}