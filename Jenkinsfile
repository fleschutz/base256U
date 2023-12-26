pipeline {
    agent any  
    stages {
        stage ('Cleanup') {
            steps {
		echo "Pulled from ${env.GIT_URL}, branch ${env.GIT_BRANCH}, commit {$env.GIT_COMMIT} ..."
                sh 'git clean -d --force'
                sh 'git status'
	    }
	}
        stage ('Build') {
            steps {
		echo "Starting build #${env.BUILD_NUMBER} on ${env.NODE_NAME} node ..."
                sh 'cmake --version'
                sh 'cmake .'
                sh 'make --version'
                sh 'make'
            }
        }
        stage ('Test') {
            steps {
                sh './base256'
            }
        }
        stage ('Zip') {
            steps {
                sh 'zip base256.zip README.md LICENSE base256'
            }
        }
	stage ('Archive') {
		steps {
                    archiveArtifacts artifacts: 'base256.zip', fingerprint: true, onlyIfSuccessful: true
		}
	}
    }
}
