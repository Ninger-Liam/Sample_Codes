let xvel, yvel;
let ballX, ballY;
let ballD = 25;
let pddlX = 300;
let pddlY = 550;
let pddlW = 100;
let pddlH = 30;
let score = 0;
let lives = 3;
let cRed = 51;
let cGreen = 255;
let cBlue = 62;
let ballRed = 255;
let ballBlue = 0;
let ballGreen = 0;
let isLooping = true;

function setup(){
    createCanvas(600, 600);
    ballX = random(0, 300);
    ballY = random(0, 300);
    xvel = random(1, 3);
    yvel = random(1, 3);
}
function draw(){
    background(0);
    fill(255);
    noStroke();
    rect(pddlX, pddlY, pddlW, pddlH);

    fill(ballRed, ballGreen, ballBlue);
    noStroke();
    circle(ballX, ballY, ballD);

    textSize(24);
    fill(cRed, cGreen, cBlue);
    text("Score:" + score, 485, 30);
    fill(cRed, cGreen, cBlue);
    text("Lives:" + lives, 30, 30);
    ballX += xvel;
    ballY += yvel;

    if (ballX + ballD/2 >= width || ballX <= 0){
        xvel = -xvel;
    }
    if (ballY - ballD/2 <= 0){
        yvel = -yvel;
    }
    if (collide() == true){
        yvel = -yvel;
        if(yvel < 0){
            yvel -= .5;
        }
        else{
            yvel += .5;
        }
        xvel += .5;
        score++;
    }

    if (keyIsPressed){
        if(keyCode == LEFT_ARROW && pddlX > 0){
            pddlX -= 5;
        }
        else if (keyCode == RIGHT_ARROW && pddlX + pddlW < width){
            pddlX += 5;
        }
    }

    if (ballY + ballD > height){
        lives--;
        if (lives == 0){
            textSize(36);
            fill(cRed, cGreen, cBlue);
            text("GAME OVER", 200, 300);
            textSize(24);
            fill(cRed, cGreen, cBlue);
            text("Click to Restart!", 225, 350);
            redraw();
            isLooping = false;
            noLoop();
            return;
        }
        isLooping = false;
        noLoop();
        if (isLooping == false){
            textSize(24);
            fill(cRed, cGreen, cBlue);
            text("Click to Resume!", 200, 300);
        }
    }
}

function mousePressed(){
    if (isLooping == false){
        if (lives == 0){
            lives = 3;
            score = 0;
            xvel = floor(random(1, 3));
            yvel = floor(random(1, 3));
            ballX = 300;
            ballY = 30;
            isLooping = true;
            loop();
        }
        else{
            ballX = 300;
            ballY = 30;
            let xran = floor(random(0, 1));
            let yran = floor(random(0, 1));
            if (score >= 8){
                if (xran == 0){
                   xvel = -4;
                }
                else{
                    xvel = 4;
                }
                if(yran == 0){
                    yvel = -4;
                }
                else{
                    yvel = 4;
                }
            }
            else{
                if (xran == 0){
                   xvel = floor(random(-1, -3));
                }
                else{
                    xvel = floor(random(1, 3));
                }
                if (yran == 0){
                    yvel = floor(random(-1, -3));
                }
                else{
                    yvel = floor(random(1, 3));
                }
            }
        }
        isLooping = true;
        loop();
    }
}

function collide(){
    let ballR = ballD/2;
    if (ballY + ballR >= pddlY && ballX >= pddlX && ballX <= pddlX + pddlW){
        return true;
    }
}