//
//  WelcomeViewController.swift
//  Power Cost
//
//  Created by Rushi Patel on 2021-01-25.
////  STUDENT ID: 108189192

import UIKit

class WelcomeViewController: UIViewController {
    @IBOutlet var holderView: UIView!;
    let scrollView = UIScrollView()
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .red;
        // Do any additional setup after loading the view.
    }
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews();
        configure();
    }
    private func configure(){
        scrollView.frame = holderView.bounds;
        holderView.addSubview(scrollView);
        
        for x in 0...3 {
            let pageView = UIView(frame: CGRect(x: CGFloat(x) * (holderView.frame.size.width), y: 0, width: holderView.frame.size.width, height: holderView.frame.size.height));
            scrollView.addSubview(pageView);
            pageView.backgroundColor = .black;
            let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: holderView.frame.size.width, height: holderView.frame.size.height - 65 ))
            
            let btnView = UIButton(frame: CGRect(x: 10, y: pageView.frame.size.height - 60, width: holderView.frame.size.width - 20, height: 50))
            imageView.contentMode = .scaleAspectFit;
            imageView.image = UIImage(named: "s\(x+1)");
            pageView.addSubview(imageView);
            btnView.setTitleColor(.red, for: .normal)
            btnView.backgroundColor = .black;            btnView.setTitle("Continue->", for: .normal);
            btnView.setTitleColor(.red, for: .normal);
            if x == 2 {
                btnView.setTitle("Get Started", for: .normal)
            }
            btnView.addTarget(self, action: #selector(didTapButton(_:)), for: .touchUpInside)
            
            btnView.tag = x + 1;

            pageView.addSubview(btnView)
        }
        scrollView.contentSize = CGSize(width: holderView.frame.size.width * 3, height: 0);
        scrollView.isPagingEnabled = true;
        
    }
    @objc func didTapButton(_ button : UIButton){
        guard button.tag < 3 else {
            Core.shared.isnotnew()
            dismiss(animated: true, completion: nil)
            return
        }
        scrollView.setContentOffset(CGPoint(x: holderView.frame.size.width * CGFloat(button.tag), y: 0), animated: true)
    }
}
