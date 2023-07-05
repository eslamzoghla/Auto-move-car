
//-------------------------------- variables defination ------------------------------------
#define input1_right_motor 11
#define input2_right_motor 12
#define input1_left_motor 10
#define input2_left_motor 9
#define enable_right_motor 5
#define enable_left_motor 6

//------------------ trager forward ----------------------
#define trager_forward 13
#define ehco_forward 8

//------------------ trager right ------------------------
#define trager_right 7
#define ehco_right 4

//------------------ trager left -------------------------
#define trager_left 3
#define ehco_left 2

//------------------ definetion speed --------------------
int speed_right_motor = 122;
int speed_left_motor = 120;

int angle_degree = 80;
//------------------ distance defination -----------------
float forward_distance = 0;
float right_distance = 0;
float left_distance = 0;
int minmum_forward_distance = 10;
int minmum_right_left_distance = 20;

//------- veliacty and angler veliacty defination --------
float veliacty = 0.0515;
float right_angler_veliacty = 0.173;
float left_angler_veliacty = 0.136;

void setup() {
  //-------------------------------- define Pins  ------------------------------------
  pinMode(input1_right_motor, OUTPUT);
  pinMode(input2_right_motor, OUTPUT);
  pinMode(input1_left_motor, OUTPUT);
  pinMode(input2_left_motor, OUTPUT);
  pinMode(enable_right_motor, OUTPUT);
  pinMode(enable_left_motor, OUTPUT);
  
  //----------- define forward pins -------------
  pinMode(trager_forward, OUTPUT); //13
  pinMode(ehco_forward, INPUT); //8
  
  //----------- define right pins ---------------
  pinMode(trager_right, OUTPUT); //7
  pinMode(ehco_right, INPUT); //4
  
  //----------- define left pins ----------------
  pinMode(trager_left, OUTPUT); //3
  pinMode(ehco_left, INPUT); //2

  Serial.begin(9600);
}

void loop() {

  forward_distance_read(); // calculate forward distance
  right_distance_read();   // calculate right distance  
  left_distance_read();    // calculate left distance
  
  if (forward_distance < minmum_forward_distance)
  { // ------------------------------------------- Start if --------------------------------------------
    stop_motor();
    if (right_distance > minmum_right_left_distance) {
      rotation_degree(angle_degree, 'R');
      move_forward_motor();
      delay(200);
    }
    else if (left_distance > minmum_right_left_distance) {
      rotation_degree(angle_degree, 'L');
      move_forward_motor();
      delay(200);
    }
    else {
      rotation_degree(2*angle_degree, 'L');
      move_forward_motor();
    }
  }// ------------------------------------------- End if --------------------------------------------
  else {
    move_forward_motor();
    if (right_distance > minmum_right_left_distance) {
      delay(500);
      stop_motor();
      rotation_degree(angle_degree, 'R');
      move_forward_motor();
      delay(600);
    }
  }
  if (right_distance < 5) {
      rotation_degree(15, 'L');
    }
  if (left_distance < 5) {
    rotation_degree(15, 'R');
  }  
  /*for(int i=0;i<4;i++){
    move_distance(40);
  rotation_degree(90,'r');}*/
}
