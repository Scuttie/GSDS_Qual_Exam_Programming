#include <iostream>
#include <iomanip>
using namespace std;

// 추상 엔진 클래스
class Engine {
public:
    // 순수가상함수: 하위 클래스에서 반드시 구현해야 함
    virtual void startEngine() = 0;

    // 생성자/소멸자
    Engine() {}
    virtual ~Engine() {}
};

// 가솔린 엔진: 엔진 추상 클래스를 상속
class GasolineEngine : public Engine {
protected:
    float fuelEfficiency;  // 연비 (km/L 기준 예시)

public:
    // 생성자: 연비를 초기화
    GasolineEngine(float fuelEfficiency)
        : fuelEfficiency(fuelEfficiency) {}
    
    // 가솔린 엔진 시동
    void startEngine() override {
        cout << "Gasoline engine started." << endl;
    }

    // 멤버 변수 연비 반환
    float getFuelEfficiency() {
        return fuelEfficiency;
    }

    // 주어진 거리(km)에 대한 연료 소모량(L) 계산
    float computeFuelConsumption(float distance) {
        return distance / fuelEfficiency;
    }
};

// 하이브리드 엔진: 가솔린 엔진을 상속받아서 기능 확장
class HybridEngine : public GasolineEngine {
protected:
    float batteryCapacity;   // 배터리 용량 (kWh)
    float efficiencyFactor;  // 전기모드 효율 계수
    bool hybridMode;         // 하이브리드 모드 여부

public:
    // 생성자: 가솔린 연비, 배터리용량, 효율계수, 하이브리드 모드 설정
    HybridEngine(float fuelEfficiency, float batteryCapacity, float efficiencyFactor, bool hybridMode)
        : GasolineEngine(fuelEfficiency), batteryCapacity(batteryCapacity), efficiencyFactor(efficiencyFactor), hybridMode(hybridMode) {}
    
    // 하이브리드 엔진 시동: 가솔린 엔진 + 하이브리드 모드 시 전기 모터 사용 표시
    void startEngine() override {
        cout << "Hybrid engine started." << endl;
        
        // 부모 클래스의 startEngine()도 호출
        GasolineEngine::startEngine();
        
        // 하이브리드 모드가 활성화된 경우, 전기 모터도 시동
        if (hybridMode){
            cout << "Electric motor started." << endl;
        }
    }

    // 하이브리드 엔진 사양 출력
    void displaySpecs() {
        cout << "Hybrid engine specifications:" << endl;
        cout << "Fuel efficiency: " << fuelEfficiency << endl;
        cout << "Battery capacity: " << batteryCapacity << endl;
        if (hybridMode) {
            cout << "Hybrid mode: Enabled" << endl;
        } else {
            cout << "Hybrid mode: Disabled" << endl;
        }
    }

    // 주어진 거리(km)에 대한 배터리 소모량(kWh) 계산
    float computeBatteryConsumption(float distance) {
        return distance / efficiencyFactor;
    }

    // 주행 거리(km)에 따른 가솔린 + 전기모터 통합 소모량 계산 및 출력
    void computeTotalPowerConsumption(float distance) {
        if (hybridMode) {
            // 하이브리드 모드: 70%는 가솔린, 30%는 전기 사용
            float fuelConsumption = 0.7f * computeFuelConsumption(distance);
            float batteryConsumption = 0.3f * computeBatteryConsumption(distance);

            // 가솔린 1리터 -> 대략 9.7 kWh로 환산
            float totalPowerConsumption = (fuelConsumption * 9.7f) + batteryConsumption;

            cout << "Computing power consumption for " << distance << " km:" << endl;
            cout << "Fuel used: " << fuelConsumption << " liters" << endl;
            cout << "Battery used: " << batteryConsumption << " kWh" << endl;
            cout << "Total power used: " << totalPowerConsumption << " kWh" << endl;
        }
        else {
            // 하이브리드 모드가 아닌 경우: 전량 가솔린 사용
            float fuelConsumption = computeFuelConsumption(distance);
            float batteryConsumption = 0.0f;  // 전기 사용량은 0
            float totalPowerConsumption = fuelConsumption * 9.7f;

            cout << "Computing power consumption for " << distance << " km:" << endl;
            cout << "Fuel used: " << fuelConsumption << " liters" << endl;
            cout << "Battery used: " << batteryConsumption << " kWh" << endl;
            cout << "Total power used: " << totalPowerConsumption << " kWh" << endl;
        }
    }
};


// 메인 함수: 위에서 구현한 클래스들을 테스트
int main() {
    // 출력 시 소수점 한 자리까지 표시
    cout << std::fixed << setprecision(1);

    // 1) 가솔린 엔진 테스트
    GasolineEngine gasoline(20);
    gasoline.startEngine();
    cout << "Fuel consumption is " << gasoline.computeFuelConsumption(100) << " liters." << endl;

    // 2) 하이브리드 엔진 (hybridMode = true)
    HybridEngine hybrid(18.5, 15.0, 7.0, true);
    hybrid.startEngine();
    hybrid.displaySpecs();
    hybrid.computeTotalPowerConsumption(100);

    // 3) 하이브리드 엔진 (hybridMode = false)
    HybridEngine hybrid2(18.5, 15.0, 7.0, false);
    hybrid2.startEngine();
    hybrid2.displaySpecs();
    hybrid2.computeTotalPowerConsumption(100);

    return 0;
}
