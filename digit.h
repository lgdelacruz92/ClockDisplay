class Digit {
public:
  bool _a;
  bool _b;
  bool _c;
  bool _d;
  bool _e;
  bool _f;
  bool _g;
  
  Digit() {
    _a = false;
    _b = false;
    _c = false;
    _d = false;
    _e = false;
    _f = false;
    _g = false;
  }

  void reset() {
    _a = false;
    _b = false;
    _c = false;
    _d = false;
    _e = false;
    _f = false;
    _g = false;
  }

  void zero() {
    _a = true;
    _b = true;
    _c = true;
    _d = true;
    _e = true;
    _f = true;
    _g = false;
  }

  void one() {
    _a = false;
    _b = true;
    _c = true;
    _d = false;
    _e = false;
    _f = false;
    _g = false;
  }

  void two() {
    _a = true;
    _b = true;
    _c = false;
    _d = true;
    _e = true;
    _f = false;
    _g = true;
  }

  void three() {
    _a = true;
    _b = true;
    _c = true;
    _d = true;
    _e = false;
    _f = false;
    _g = true;
  }

  void four() {
    _a = false;
    _b = true;
    _c = true;
    _d = false;
    _e = false;
    _f = true;
    _g = true;
  }

  void five() {
    _a = true;
    _b = false;
    _c = true;
    _d = true;
    _e = false;
    _f = true;
    _g = true;
  }

  void six() {
    _a = true;
    _b = false;
    _c = true;
    _d = true;
    _e = true;
    _f = true;
    _g = true;
  }

  void seven() {
    _a = true;
    _b = true;
    _c = true;
    _d = false;
    _e = false;
    _f = false;
    _g = false;
  }

  void eight() {
    _a = true;
    _b = true;
    _c = true;
    _d = true;
    _e = true;
    _f = true;
    _g = true;
  }

  void nine() {
    _a = true;
    _b = true;
    _c = true;
    _d = false;
    _e = false;
    _f = true;
    _g = true;
  }
};
