from setuptools import find_packages
from setuptools import setup

package_name = 'zeabus_vision'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    author='shayennn',
    author_email='me@shayennn.com',
    maintainer='shayennn',
    maintainer_email='me@shayennn.com',
    keywords=['ROS', 'Zeabus', 'Vision', 'Robosub2019'],
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python',
        'Topic :: Software Development',
    ],
    description='Zeabus vision pkg for Robosub2019',
    license='Apache License, Version 2.0',
    test_suite='test',
    entry_points={
        'console_scripts': [
            'gate = gate.finder:main'
        ],
    },


)
