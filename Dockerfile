FROM drogonframework/drogon
RUN apt update -y
RUN apt-get install -y tree git curl wget
WORKDIR /training
