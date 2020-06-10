let xvel, yvel;
let ballX, ballY;
let ballD = 25;

let pddlX = 300;
let pddlY = 540;
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

let bricks = [];
let brick;
// let brickNum = 0;

let isLooping = true;

function setup(){
    createCanvas(600, 600);
    ballX = random(300, 400);
    ballY = random(300, 400);
    xvel = random(1, 3);
    yvel = random(1, 3);

    for (let i = 0; i < 15; i++){
        if (i < 5){
            brick = {
                x: 3 + (120 * i),
                y: 5,
                l: 30,
                w: 110,
                h: 3,
                color: {
                    r: 0,
                    g: 0,
                    b: 0
                }
            }
        }
        if (i < 10 && i >= 5){
            brick = {
                x: 3 + (120 * (i % 5)),
                y: 45,
                l: 30,
                w: 110,
                h: 2,
                color: {
                    r: 0,
                    g: 0,
                    b: 0
                }
            }
        }
        if (i >= 10){
            brick = {
                x: 3 + (120 * (i % 5)),
                y: 85,
                l: 30,
                w: 110,
                h: 1,
                color: {
                    r: 0,
                    g: 0,
                    b: 0
                }
            }
        }
        bricks[i] = brick;
    }
}
function draw(){
    ballRed = 255;
    background(0);
    fill(255);
    noStroke();
    rect(pddlX, pddlY, pddlW, pddlH);

    fill(ballRed, ballGreen, ballBlue);
    noStroke();
    circle(ballX, ballY, ballD);

    textSize(24);
    fill(cRed, cGreen, cBlue);
    textSize(18);
    text("Score: " + score, 20, 585);
    fill(cRed, cGreen, cBlue);
    text("Lives: " + lives, 500, 585);
    ballX += xvel;
    ballY += yvel;

    for (let brick of bricks){
        if (brick.h == 3){
            brick.color.r = 255;
            brick.color.g = 0;
            brick.color.b = 0;
        }
        if (brick.h == 2){
            brick.color.r = 0;
            brick.color.g = 0;
            brick.color.b = 255;
        }
        if (brick.h == 1){
            brick.color.r = 0;
            brick.color.g = 255;
            brick.color.b = 0;
        }
        fill(brick.color.r, brick.color.g, brick.color.b)
        rect(brick.x, brick.y, brick.w, brick.l);
    }

    if (ballX + ballD/2 >= width || ballX <= 0){
        xvel = -xvel;
    }
    if (ballY - ballD/2 <= 0){
        yvel = -yvel;
    }
    if (collide() == true){
        yvel = -yvel;


    }

    if (keyIsPressed){
        if(keyCode == LEFT_ARROW && pddlX > 0){
            pddlX -= 5;
        }
        else if (keyCode == RIGHT_ARROW && pddlX + pddlW < width){
            pddlX += 5;
        }
    }

    hitBrick();

    if (ballY + ballD/2 > height + 50){
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
    if (score == 30){
        textSize(36);
        fill(cRed, cGreen, cBlue);
        text("YOU WIN!!", 200, 300);
        textSize(24);
        fill(cRed, cGreen, cBlue);
        text("Click to Restart!", 205, 350);
        redraw();
        isLooping = false;
        noLoop();
        return;
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
            ballY = 300;
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
    if (ballY + ballR >= pddlY && ballX >= pddlX && ballX <= pddlX + pddlW && ballY <= pddlY + pddlH){
        return true;
    }
}

function hitBrick(){
    let ballR = ballD/2;
    for (let i = bricks.length - 1; i >= 0; i--){
        if (ballY + ballR >= bricks[i].y &&
        ballX >= bricks[i].x &&
        ballX <= bricks[i].x + bricks[i].w &&
        ballY <= bricks[i].y + bricks[i].l){
            // bricks.splice(i, 1);
            bricks[i].h--;
            yvel = -yvel;
            if(yvel < 0){
                yvel -= .5;
            }
            else{
                yvel += .5;
            }
            xvel += .5;
            score++;
            if (bricks[i].h == 0){
                bricks.splice(i, 1);
            }
        }
    }
}