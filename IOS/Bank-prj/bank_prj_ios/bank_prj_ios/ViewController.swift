//
//  ViewController.swift
//  bank_prj_ios
//
//  Created by Rushi Patel on 2021-02-02.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet var acc_uv : UITextField!
    @IBOutlet var pass_uv : UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    @IBAction func verify(){
        if(acc_uv.text == nil || pass_uv.text == nil){
            
        }
        else{
        let usr_num:String = String(acc_uv.text!);
        let usr_pass: String = String(pass_uv.text!);
    
        let usr = verify_usr();
        let isusr = usr.isVerified(usr_num: usr_num, usr_pass: usr_pass);
            if( isusr == 1){
                // perform something or makes the user enter
            }else{
                
            }
        }
    }

}

