void Serial_receive() {
  while (Serial2.available() > 0) {
    head_CAM = Serial2.read();
    if (head_CAM == 255) {
      CAM_angle = Serial2.read();
      CAM_distance = Serial2.read();
      break;
    }
  }

  while (Serial3.available() > 0) {
    head_USS = Serial3.read();
    if (head_USS == 255) {
      USS = Serial3.read();
      USS1 = Serial3.read();
      USS2 = Serial3.read();
      USS3 = Serial3.read();
      USS4 = Serial3.read();
      break;
    }
  }

  if (Serial4.available() > 0) {
    IMU = Serial4.read();
  }

  CAM_angle = CAM_angle * 2;
  
  if (IMU < 90) {
    IMU = IMU + 90;
  } else {
    IMU = IMU - 90;
  }
}