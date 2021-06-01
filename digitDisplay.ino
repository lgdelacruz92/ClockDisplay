
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

const int ZERO[]  = { 1, 1, 1, 1, 1, 1, 0 };
const int ONE[]   = { 0, 1, 1, 0, 0, 0, 0 };
const int TWO[]   = { 1, 1, 0, 1, 1, 0, 1 };
const int THREE[] = { 1, 1, 1, 1, 0, 0, 1 };
const int FOUR[]  = { 0, 1, 1, 0, 0, 1, 1 };
const int FIVE[]  = { 1, 0, 1, 1, 0, 1, 1 };
const int SIX[]   = { 1, 0, 1, 1, 1, 1, 1 };
const int SEVEN[] = { 1, 1, 1, 0, 0, 0, 0 };
const int EIGHT[] = { 1, 1, 1, 1, 1, 1, 1 };
const int NINE[]  = { 1, 1, 1, 0, 0, 1, 1 };

void preSetup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void writeNumber(int num[], int s) {
  for (int i = 0; i < s; i++) {
    digitalWrite(i + 2, num[i]);
  }
}

int** nums;
int i = 0;

void setup() {
  // put your setup code here, to run once:

  preSetup();
  nums = malloc(10 * sizeof(int*));
  nums[0] = ZERO;
  nums[1] = ONE;
  nums[2] = TWO;
  nums[3] = THREE;
  nums[4] = FOUR;
  nums[5] = FIVE;
  nums[6] = SIX;
  nums[7] = SEVEN;
  nums[8] = EIGHT;
  nums[9] = NINE;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  if (i >= 10) {
    i %= 10;
  }
  String index = String(i);
  Serial.println("Writing" + index);
  writeNumber(nums[i], 7);
  i++;
}
