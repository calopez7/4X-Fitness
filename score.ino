void initializeScore(SevSeg score) {
  byte numDigits = 4;
  byte digitPins[] = {1,2,3,4};
  byte segmentPins[] = {13,6,11,9,8,7,12,10};

  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  score.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);

score.setBrightness(10);
  score.setNumber(1234,0);
}
