pipeline {
    agent any  
    stages {
        stage ('Check') {
            steps {
		echo "Pulled from ${env.GIT_URL}, branch ${env.GIT_BRANCH}, commit {$env.GIT_COMMIT} ..."
                sh 'git fsck'
                sh 'cmake --version'
                sh 'make --version'
	    }
	}
        stage ('Build') {
            steps {
		echo "Starting build #${env.BUILD_NUMBER} on host ${env.HOSTNAME} ..."
                sh 'git clean -d --force'
                sh 'git status'
                sh 'cmake .'
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
