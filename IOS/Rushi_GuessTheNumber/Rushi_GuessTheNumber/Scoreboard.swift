//
//  ScoreBoard.swift
//  Rushi_GuessTheNumber
//
//  Created by Rushi Patel on 2021-02-24.
//

import UIKit

class ScoreBoard: UIViewController{
    var x1 = won;
    var x2 = lost;
    @IBOutlet weak var t1: UILabel!
    @IBOutlet weak var t2: UILabel!
    override func viewDidLoad() {
        print(x1);
        print(x2);
        t1.text = String(x1);
        t2.text = String(x2)
        super.viewDidLoad()
        //t1.text = String(won);
     //   t2.text = String(lost);
        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
