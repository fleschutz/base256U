pipeline {
    agent any  
    stages {
        stage('Build') {
            steps {
                script {
                    currentBuild.displayName = "base256"
                    currentBuild.description = "Pipeline for the base256 executable."
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
                sh 'zip -r base256.zip .'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: 'base256.zip', fingerprint: true, onlyIfSuccessful: true
        }
    }
}
