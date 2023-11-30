pipeline {
    agent any  
    stages {
        stage('Build') {
            steps {
                buildDescription 'my build'
                script {
                    currentBuild.displayName = "base256"
                    currentBuild.description = "Pipeline to build the base256 executable."
                }
                sh 'cmake .'
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
    }
    post {
        always {
            archiveArtifacts artifacts: 'base256.zip', fingerprint: true, onlyIfSuccessful: true
        }
    }
}
