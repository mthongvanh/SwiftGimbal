//
//  PulseView.swift
//  SwiftGimbal
//
//  Created by Michael Thongvanh on 11/26/14.
//  Copyright (c) 2014 Chisel Apps. All rights reserved.
//

import Foundation

class PulseView: UIView {
    // MARK: - Properties -
    let STRONGEST_POSSIBLE_SIGNAL: Float = -40
    var widthConstraint: NSLayoutConstraint?
    var heightConstraint: NSLayoutConstraint?
    var pulseColor: UIColor?
    let startColor: UIColor = UIColor(red: 0.5, green: 0, blue: 0, alpha: 1)
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        // to avoid constraint conflicts from programmatically adding constraints, 
        // disable translating autoresizing masks into constraints
        setTranslatesAutoresizingMaskIntoConstraints(false)
        widthConstraint = NSLayoutConstraint(item: self, attribute: NSLayoutAttribute.Width, relatedBy: NSLayoutRelation.Equal, toItem:nil, attribute:NSLayoutAttribute.Width, multiplier:1.0, constant:frame.size.width)
        heightConstraint = NSLayoutConstraint(item: self, attribute: NSLayoutAttribute.Height, relatedBy: NSLayoutRelation.Equal, toItem:nil, attribute:NSLayoutAttribute.Height, multiplier:1.0, constant:frame.size.height)
        addConstraints([widthConstraint!,heightConstraint!])
        
        backgroundColor = UIColor.clearColor()
        pulseColor = startColor
    }
    
    required init(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    override func drawRect(rect: CGRect) {
        // CGGradient drawing code adapted from the Quartz2D Programming Guide
        // https://developer.apple.com/library/ios/documentation/GraphicsImaging/Conceptual/drawingwithquartz2d/dq_shadings/dq_shadings.html
        var context = UIGraphicsGetCurrentContext()
        var gradient: CGGradientRef
        var colorspace: CGColorSpaceRef
        var locations: [CGFloat] = [0.0, 1.0]
        
        var circleColor = pulseColor!.CGColor
        var colors = [UIColor.clearColor().CGColor,circleColor];
        colorspace = CGColorSpaceCreateDeviceRGB();
        gradient = CGGradientCreateWithColors(colorspace, colors as CFArrayRef, locations);
        
        var startPoint = CGPoint()
        var endPoint = CGPoint()
        
        var startRadius: CGFloat
        var endRadius: CGFloat
        
        var midX = CGRectGetMidX(rect)
        var midY = CGRectGetMidY(rect)
        
        startPoint.x = midX
        startPoint.y = midY
        
        endPoint.x = midX
        endPoint.y = midY
        
        startRadius = 0.0
        endRadius = CGRectGetWidth(self.frame)/2.0
        
        CGContextDrawRadialGradient(context, gradient, startPoint, startRadius, endPoint, endRadius, 0)
        
        // radial gradient looks jagged, so create a circle to smooth the edge
        createBezierCircle(rect, circleColor:circleColor)
    }

    override func layoutSubviews() {
        super.layoutSubviews()
    }
    
    func createBezierCircle(rect: CGRect, circleColor color: CGColorRef) {
        // Create an oval shape to draw.
        var aPath = UIBezierPath(ovalInRect:rect)
        // Set the render colors.
        UIColor.blueColor().setStroke()
        var aRef = UIGraphicsGetCurrentContext()
        // If you have content to draw after the shape,
        // save the current state before changing the transform.
        CGContextSaveGState(aRef);
        // Adjust the drawing options as needed.
        aPath.lineWidth = 0.25
        // Fill the path before stroking it so that the fill
        // color does not obscure the stroked line.
        aPath.stroke()
        // Restore the graphics state before drawing any other content.
        CGContextRestoreGState(aRef);
    }
    
    func growShrinkCircle(repeats: Bool, duration: NSTimeInterval, size: CGSize?) {
        var targetSize: CGSize
        if let desiredSize = size {
            targetSize = size!
        } else {
            targetSize = CGSizeMake(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds))
        }
        
        var growShrink = CABasicAnimation(keyPath: "bounds")
        growShrink.fromValue = NSValue(CGRect: CGRectMake(self.bounds.origin.x, self.bounds.origin.y, CGRectGetWidth(self.bounds)/2.0, CGRectGetHeight(self.bounds)/2.0))
        growShrink.toValue = NSValue(CGRect: CGRectMake(self.bounds.origin.x, self.bounds.origin.y, targetSize.width, targetSize.height))
        growShrink.autoreverses = true
        growShrink.repeatCount = 99999999
        growShrink.duration = duration
        layer.addAnimation(growShrink, forKey: "growAndShrinkCircle")
    }
    
    func changePulseColor(transmitter: FYXTransmitter, rssiStrength strength: NSNumber) {
        var newPulseSize = translateRSSIStrengthToSize(strength)
        var proximityRatio = CGFloat(STRONGEST_POSSIBLE_SIGNAL/strength.floatValue)
        // change the pulsating circle color according to the proximity of the beacon
        // blue means it is closer and more reddish means it's farther away
        pulseColor = UIColor(red: 1.0 - proximityRatio, green: 0, blue: proximityRatio, alpha: 1.0)
        // ensure drawRect gets called so the color actually changes
        setNeedsDisplay()
    }
    
    func translateRSSIStrengthToSize(transmitterStrength: NSNumber) -> CGSize {
        // be sure to avoid dividing by zero
        var strength = transmitterStrength.integerValue == 0 ? 1 : transmitterStrength.floatValue
        var translatedStrength: Float = STRONGEST_POSSIBLE_SIGNAL / strength
        var newSize = CGSizeMake(CGRectGetWidth(self.bounds)*CGFloat(translatedStrength), CGRectGetHeight(self.bounds)*CGFloat(translatedStrength))
        return newSize
    }
    
    func departed() {
        pulseColor = startColor
        setNeedsDisplay()
    }
}

