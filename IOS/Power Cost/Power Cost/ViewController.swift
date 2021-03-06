//
//  ViewController.swift
//  Power Cost
//
//  Created by Rushi Patel on 2021-01-25.
//  STUDENT ID: 108189192

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var f1 : UITextField!
    @IBOutlet var f2 : UITextField!
    @IBOutlet var f3 : UITextField!
    @IBOutlet var l1 : UILabel!
    @IBOutlet var l2 : UILabel!
    
    var charge : Float = 0.0;
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        let myColor = UIColor.white
        f1.layer.borderColor = myColor.cgColor;
        f2.layer.borderColor = myColor.cgColor;
        f3.layer.borderColor = myColor.cgColor;
          f1.layer.borderWidth = 1.0
          f2.layer.borderWidth = 1.0
          f3.layer.borderWidth = 1.0
            if Core.shared.isnewusr(){
                let vc = storyboard?.instantiateViewController(identifier: "welcome") as! WelcomeViewController;
                vc.modalPresentationStyle = .fullScreen;
                present(vc,animated: true);
            }
        }


//4.68 + 5.128+ 2.21

    @IBAction func calc_chg(){
        print("welcome here");
        var total_chrg:Float = 0.0;
        var net_bill:Float = 0.0;
        var c1:Float = 0.0;
        var c2:Float = 0.0;
        var c3:Float = 0.0;
        if(f1.text != nil && f2.text != nil && f3.text != nil ){
            c1 =  Float(f1.text!) ?? 0;
            c2 =  Float(f2.text!) ?? 0;
            c3 =  Float(f3.text!) ?? 0;
            total_chrg = (c1 * 0.132) + (c2 * 0.065) + (c3 * 0.094);
            total_chrg = round(total_chrg * 100) / 100;
            self.l1.text = " Total Cunsumption Charge: $  \(total_chrg) ";
            net_bill = total_chrg + (total_chrg * 0.13) - (total_chrg * 0.08);
            net_bill = round(net_bill * 100) / 100;
            self.l2.text = " Your net Total is $ \(net_bill)";
            l1.textColor = UIColor.white;
            l2.textColor = UIColor.white;
            
        }
    }

}

class Core{
    static let shared = Core();
    
    func isnewusr() -> Bool{
        return !UserDefaults.standard.bool(forKey: "isnewusr");
    }
    
    func isnotnew(){
        UserDefaults.standard.set(true, forKey: "isnewusr");
    }
}
