FROM aoc24:latest

ARG USER_DOCKER

RUN usermod -l ${USER_DOCKER} -d /home/${USER_DOCKER}/ -m ubuntu
RUN usermod -aG sudo ${USER_DOCKER}

USER $USER_DOCKER
