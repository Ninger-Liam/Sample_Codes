let img;
let imgX, imgY;
let imgSizeX = 90;
let imgSizeY = 90;
let xvel, yvel;
let bncCnt = -1;
let red = 255;
let green = 255;
let blue = 255;
let yay = document.querySelector("#yay");

function setup(){
  createCanvas(windowWidth, windowHeight);;
  imgX = random(0, width - imgSizeX);
  imgY = random(0, height - imgSizeY);
  xvel = random(3, 7);
  yvel = random(3, 7);
}

function preload(){
  img = loadImage('DVD2.png');
}

function draw(){
  background(0);
  tint(red, green, blue)
  stroke("white")
  image(img, imgX, imgY, imgSizeX, imgSizeY);

  imgX += xvel;
  imgY += yvel;

  if (imgX + imgSizeX >= windowWidth || imgX <= 0){
    xvel = -xvel
    if (bncCnt == -1){
      bncCnt++;
    }
    if (bncCnt == 0){
      red = random(0, 255);
      bncCnt++;
    }
    if (bncCnt == 1){
      green = random(0, 255);
      bncCnt++;
    }
    if (bncCnt == 2){
      blue = random(0, 255);
      bncCnt = 0;
    }
  }

  if (imgY + imgSizeY >= windowHeight || imgY <= 0){
    yvel = -yvel
    if (bncCnt == -1){
      bncCnt++
    }
    if (bncCnt == 0){
      red = random(0, 255);
      bncCnt++;
    }
    if (bncCnt == 1){
      green = random(0, 255);
      bncCnt++;
    }
    if (bncCnt == 2){
      blue = random(0, 255);
      bncCnt = 0;
    }
  }

  if ((imgX <= 0 && imgY <= 0) || (imgX + imgSizeX >= width && imgY + imgSizeY >= height)
  || (imgX <= 0 && imgY + imgSizeY >= height) || (imgX + imgSizeX >= width && imgY <= 0)){
    yay.play()
  }
}

function windowResized(){
  resizeCanvas(windowWidth, windowHeight);
}