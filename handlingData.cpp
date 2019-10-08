#include "handlingData.h"
#include "errors.h"
#include "randoms.h"
#include "const.h"

void handlingArtifactData(int numberOfArtifacts, std::vector<Artifact> &Artifacts) {
    std::ifstream inFile;
    inFile.open(ARTIFACT_FILE);
    std::vector<Artifact> array;

    if (!inFile) {
        errorHandling(OPEN_FILE_ERROR, ARTIFACT_FILE);
    }

    std::string line;
    size_t delimiterPos;

    while (getline(inFile, line)) {
        Artifact artifact;
        std::string name, description;
        int period;

        delimiterPos = line.find(DELIMITER);
        name = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(DELIMITER);
        description = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        period = stoi(line);

        artifact = Artifact(name, description, period);
        array.push_back(artifact);

        if (inFile.eof()) break;
    }

    if (numberOfArtifacts < MAX_ARTIFACT) {
        for (int i = 0; i < MAX_ARTIFACT - numberOfArtifacts; i++) {
            int randomIndex = intRandom(MIN_ARTIFACT, MAX_ARTIFACT - i);
            array.erase(array.begin() + randomIndex - 1);
        }
    }
    Artifacts = array;
}

void handlingChrononautsData(std::vector<Chrononaut> &Chrononauts) {
    Chrononaut chrononaut;

    chrononaut = JumpEngineer("Steve", JUMP_ENGINEER);
    chrononaut.generateActualAge();
    chrononaut.generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = Doctor("Strange", DOCTOR);
    chrononaut.generateActualAge();
    chrononaut.generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = Historian("Hulk", HISTORIAN);
    chrononaut.generateActualAge();
    chrononaut.generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = Security("Stark", SECURITY);
    chrononaut.generateActualAge();
    chrononaut.generateAbility();
    Chrononauts.push_back(chrononaut);

    chrononaut = ChronoPet("Thor", CHRONO_PET);
    chrononaut.generateActualAge();
    chrononaut.generateAbility();
    Chrononauts.push_back(chrononaut);

}
