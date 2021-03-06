//
//  ViewController.swift
//  Rushi_GuessTheNumber
//
//  Created by Rushi Patel on 2021-02-24.
//

import UIKit
var won = 0;
var lost = 0;

class ViewController: UIViewController {
    @IBOutlet weak var attempt : UILabel!
    @IBOutlet weak var answer : UILabel!
    @IBOutlet weak var asf1 : UITextField!
    @IBOutlet weak var ats : UILabel!
    private var currVal : Int?;
    private var att : Int = 5;
    override func viewDidLoad() {
        super.viewDidLoad()
        generateNo();
        // Do any additional setup after loading the view.
    }

    
    @IBAction func checkAns(){
        print(currVal);
        if(asf1.text != "" && att > 0){
        let ans : Int? = Int(asf1.text!);
        if(ans == currVal){
            answer.text = "Winner....";
            won += 1;
            
            print(lost);
            print(won);
            ats.isHidden = false;
            attempt.isHidden = false;
            answer.isHidden = false;
            let alert = UIAlertController(title: "Hooray",
                message: "Want to checkout the score board?",
                preferredStyle: .alert)
            let action1 = UIAlertAction(title: "ScoreBoard", style: .default, handler: { (action) -> Void in
                self.scoreBoard()
                })
             
                let action2 = UIAlertAction(title: "Replay", style: .default, handler: { (action) -> Void in
                    self.resetGame();
                })
             
            alert.addAction(action1)
            alert.addAction(action2)
            
            present(alert, animated: true, completion: nil)
        }else{
            if( ans! > currVal ?? 0 ){
                answer.text = "The correct answer is lesser than your guess \(ans ?? 0)";
                answer.isHidden = false;
                
                ats.isHidden = false;
                attempt.isHidden = false;
                self.att -= 1;
                attempt.text = String(self.att);
            }else{
                answer.text = "The correct answer is greater than your guess \(ans ?? 0)";
                answer.isHidden = false;
                
                ats.isHidden = false;
                attempt.isHidden = false;
                self.att -= 1;
                attempt.text = String(self.att);
            }
        
            }
            
        }else{
            if(att > 0){
                self.showErrorAlert(errorMessage: "Please Enter your guess first")}
            else{
                lost += 1;
                print(lost);
                print(won);
                let alert = UIAlertController(title: "Oops",
                    message: "Want to try again?",
                    preferredStyle:.actionSheet)
                
                let action1 = UIAlertAction(title: "ScoreBoard", style: .default, handler: { (action) -> Void in
                    self.scoreBoard()
                    })
                 
                    let action2 = UIAlertAction(title: "Replay", style: .default, handler: { (action) -> Void in
                        self.resetGame();
                    })
                 
                alert.addAction(action1)
                alert.addAction(action2)
                
                present(alert, animated: true, completion: nil)
                
            }
            
        }
    }
    
    func showErrorAlert(errorMessage : String){
        let errorAlert = UIAlertController(title: "Error", message: errorMessage, preferredStyle: .alert)
        errorAlert.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: nil))
        self.present(errorAlert, animated: true, completion: nil)
    }
    
    private func generateNo(){
        currVal =  Int.random(in: 1...25);
    }
     
    private func resetGame(){
        generateNo();
        answer.isHidden = true;
        asf1.text = "";
        attempt.text = "5";
        attempt.isHidden = true;
        att = 5;
        ats.isHidden = true;
    }
    
    private func scoreBoard(){
      //  prepare(for: ScoreBoard, sender: nil)
        let storyboard = UIStoryboard(name: "Main", bundle: Bundle.main)
        let baba = storyboard.instantiateViewController(identifier: "baba");
        self.navigationController?.pushViewController(baba, animated: true)
    }

}

