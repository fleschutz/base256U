pipeline {
    agent any  
    stages {
        stage('Build') {
            steps {
		echo "Building from branch: ${env.BRANCH_NAME}, build number: ${env.BUILD_NUMBER}"
                sh 'cmake --version'
                sh 'rm -f CMakeCache.txt'
                sh 'cmake .'
                sh 'make --version'
                sh 'make'
            }
        }
        stage('Test') {
            steps {
                sh './base256'
            }
        }
        stage('Zip') {
            steps {
                sh 'zip base256.zip README.md LICENSE base256'
            }
        }
		stage('Archive') {
			steps {
				archiveArtifacts artifacts: 'base256.zip', fingerprint: true, onlyIfSuccessful: true
			}
		}
	}
}
