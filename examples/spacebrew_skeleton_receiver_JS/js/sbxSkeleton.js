/**
 * 
 * sbxSkeleton: Spacebrew extension for sending and receiving openNI skeleton types via spacebrew
 * --------------------------------
 * 
 * @author 		Bernardo Schorr
 * @date 		May 31, 2014
 * 
 */

//sbxSkeleton main function. Will hold the positions for each of the openNI joints received.
function skeleton () {

			this.head = {x :0, y: 0};
			this.neck = {x :0, y: 0};
			this.torso = {x :0, y: 0};

			this.left_shoulder = {x :0, y: 0};
			this.left_elbow = {x :0, y: 0};
			this.left_hand = {x :0, y: 0};

			this.right_shoulder = {x :0, y: 0};
			this.right_elbow = {x :0, y: 0};
			this.right_hand = {x :0, y: 0};

			this.left_hip = {x :0, y: 0};
			this.left_knee = {x :0, y: 0};
			this.left_foot = {x :0, y: 0};

			this.right_hip = {x :0, y: 0};
			this.right_knee = {x :0, y: 0};
			this.right_foot = {x :0, y: 0};

			this.update = function( incomingSkeleton ) {

				this.head = incomingSkeleton.head;
				this.neck = incomingSkeleton.neck;
				this.torso = incomingSkeleton.torso;
				
				this.left_shoulder = incomingSkeleton.left_shoulder;
				this.left_elbow = incomingSkeleton.left_elbow;
				this.left_hand = incomingSkeleton.left_hand;

				this.right_shoulder = incomingSkeleton.right_shoulder;
				this.right_elbow = incomingSkeleton.right_elbow;
				this.right_hand = incomingSkeleton.right_hand;

				this.left_hip = incomingSkeleton.left_hip;
				this.left_knee = incomingSkeleton.left_knee;
				this.left_foot = incomingSkeleton.left_foot;

				this.right_hip = incomingSkeleton.right_hip;
				this.right_knee = incomingSkeleton.right_knee;
				this.right_foot = incomingSkeleton.right_foot;
			}

			this.draw = function ( ctx ) {

				var jointSize = 10;

				//draw the nodes
				ctx.fillRect (this.head.x-jointSize/2, this.head.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.neck.x-jointSize/2, this.neck.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.torso.x-jointSize/2, this.torso.y-jointSize/2, jointSize, jointSize);

				ctx.fillRect (this.left_shoulder.x-jointSize/2, this.left_shoulder.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.left_elbow.x-jointSize/2, this.left_elbow.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.left_hand.x-jointSize/2, this.left_hand.y-jointSize/2, jointSize, jointSize);

				ctx.fillRect (this.right_shoulder.x-jointSize/2, this.right_shoulder.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.right_elbow.x-jointSize/2, this.right_elbow.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.right_hand.x-jointSize/2, this.right_hand.y-jointSize/2, jointSize, jointSize);

				ctx.fillRect (this.left_hip.x-jointSize/2, this.left_hip.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.left_knee.x-jointSize/2, this.left_knee.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.left_foot.x-jointSize/2, this.left_foot.y-jointSize/2, jointSize, jointSize);

				ctx.fillRect (this.right_hip.x-jointSize/2, this.right_hip.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.right_knee.x-jointSize/2, this.right_knee.y-jointSize/2, jointSize, jointSize);
				ctx.fillRect (this.right_foot.x-jointSize/2, this.right_foot.y-jointSize/2, jointSize, jointSize);

				//draw the connections
				ctx.beginPath();
				
				//head to neck to torso
				ctx.moveTo (this.head.x, this.head.y);
				ctx.lineTo (this.neck.x, this.neck.y);

				ctx.moveTo (this.neck.x, this.neck.y);
				ctx.lineTo (this.torso.x, this.torso.y);

				//neck to shoulders
				ctx.moveTo (this.neck.x, this.neck.y);
				ctx.lineTo (this.left_shoulder.x, this.left_shoulder.y);

				ctx.moveTo (this.neck.x, this.neck.y);
				ctx.lineTo (this.right_shoulder.x, this.right_shoulder.y);

				//left arm
				ctx.moveTo (this.left_shoulder.x, this.left_shoulder.y);
				ctx.lineTo (this.left_elbow.x, this.left_elbow.y);

				ctx.moveTo (this.left_elbow.x, this.left_elbow.y);				
				ctx.lineTo (this.left_hand.x, this.left_hand.y);

				//right arm
				ctx.moveTo (this.right_shoulder.x, this.right_shoulder.y);
				ctx.lineTo (this.right_elbow.x, this.right_elbow.y);

				ctx.moveTo (this.right_elbow.x, this.right_elbow.y);				
				ctx.lineTo (this.right_hand.x, this.right_hand.y);

				//torso to knees
				ctx.moveTo (this.torso.x, this.torso.y);
				ctx.lineTo (this.left_hip.x, this.left_hip.y);

				ctx.moveTo (this.torso.x, this.torso.y);
				ctx.lineTo (this.right_hip.x, this.right_hip.y);

				//left leg
				ctx.moveTo (this.left_hip.x, this.left_hip.y);
				ctx.lineTo (this.left_knee.x, this.left_knee.y);

				ctx.moveTo (this.left_knee.x, this.left_knee.y);
				ctx.lineTo (this.left_foot.x, this.left_foot.y);

				//right leg
				ctx.moveTo (this.right_hip.x, this.right_hip.y);
				ctx.lineTo (this.right_knee.x, this.right_knee.y);

				ctx.moveTo (this.right_knee.x, this.right_knee.y);
				ctx.lineTo (this.right_foot.x, this.right_foot.y);

				ctx.stroke();
			}
		}