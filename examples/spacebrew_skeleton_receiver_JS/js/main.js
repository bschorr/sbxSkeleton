var canvas = document.getElementById('myCanvas');

//Check if the browser supports canvas
if(canvas.getContext){
	/*---------- VARIABLES ----------*/
	//Getting canvas context
	var ctx = canvas.getContext('2d');

	//Canvas position
	var canvasPosition;

	//Canvas size adjustment for Chrome and Firefox
	var ratio;

	//Adjusting the size to work with Firefox and Chrome at retina resolutions 
	function canvasAdjustment(){
    // finally query the various pixel ratios
    var devicePixelRatio  = window.devicePixelRatio || 1;
    //console.log(devicePixelRatio);
    var backingStoreRatio = ctx.webkitBackingStorePixelRatio ||
                            ctx.mozBackingStorePixelRatio ||
                            ctx.msBackingStorePixelRatio ||
                            ctx.oBackingStorePixelRatio ||
                            ctx.backingStorePixelRatio || 1;

    ratio = devicePixelRatio / backingStoreRatio;
    //console.log(ratio);
    
    // upscale the canvas if the two ratios don't match
	    if (devicePixelRatio !== backingStoreRatio) {

	        var oldWidth = canvas.width;
	        var oldHeight = canvas.height;

	        canvas.width = oldWidth * ratio;
	        canvas.height = oldHeight * ratio;

	        canvas.style.width = oldWidth + 'px';
	        canvas.style.height = oldHeight + 'px';

			ctx.scale(ratio, ratio);				        
	    }
  	}

	function setup(){
		draw();
	}						

	// var n = 0;
	
	function draw(){

		ctx.fillStyle = '#fff';
		ctx.fillRect(0, 0, canvas.width/ratio, canvas.height/ratio);

		ctx.fillStyle = '#000';
		mySkeleton.draw( ctx );


		//console.log(squares.length);
		requestAnimationFrame (draw);

	}
	
	//Adjusting for retina
	//canvasAdjustment();
	ratio = 1;

	//Calling the setup function
	setup();		


//If the browser doesn't support canvas
} else {
	alert('Your browser doesn\'t support canvas');
}